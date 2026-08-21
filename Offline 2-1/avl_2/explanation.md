# Interval Scheduler — Full Explanation (Viva-Ready)

## Part 1: What problem are we even solving?

Imagine you're building a **calendar / meeting room booking system**. Each event has:
- an **id** (auto-generated, like a booking number)
- a **start** time
- an **end** time

You need to support, fast, at scale (thousands of events):

| Command | Real-world meaning |
|---|---|
| `ADD s e` | Book a new event from `s` to `e` |
| `REMOVE id` | Cancel booking `id` |
| `UPDATE id s e` | Reschedule booking `id` to a new time |
| `CONFLICT s e` | "Can I book `s` to `e`? Does it clash with anything?" |
| `OVERLAPS s e` | "Which bookings clash with `s` to `e`?" (give me all of them) |
| `AT t` | "What's happening right now, at time `t`?" |
| `NEXT t` | "What's the very next thing happening at or after `t`?" |

The naive way: store all events in a list/array. For `CONFLICT`, `OVERLAPS`, `AT` you'd loop through **every single event** — O(n) per query. With thousands of events and thousands of queries, that's slow.

**The fix: store events in a self-balancing binary search tree (AVL tree), augmented with extra info, so every operation costs roughly O(log n) instead of O(n).**

That's the whole point of this code. Everything below exists to make that possible.

---

## Part 2: The two big ideas that make this work

### Idea 1 — AVL Tree (self-balancing BST)

A plain BST can degrade into a straight line (like a linked list) if you insert sorted data — then operations become O(n), which defeats the purpose. An **AVL tree** fixes this by keeping itself balanced: after every insert/delete, it checks if one side got too "tall" compared to the other, and **rotates** nodes around to rebalance. This guarantees height stays O(log n), so every operation (search/insert/delete) stays O(log n).

Think of it like a mobile (the hanging art piece) — if one side gets heavier, you'd shift the balance point so it doesn't tip over. The AVL tree does the digital equivalent after every insertion/deletion.

**What is the tree ordered by?** Not just `start` — by the pair `(start, id)`. Why include `id`? Because two events can have the *same* start time, and a BST needs a strict, unambiguous ordering — if two events have identical `start`, you break the tie using `id` so the tree always knows exactly where to place/find any node.

### Idea 2 — Augmented `maxEnd` (this is the "interval tree" trick)

Here's the key insight that makes `CONFLICT`, `OVERLAPS`, and `AT` fast:

> Every node stores `maxEnd` = the **largest `end` value found anywhere in its subtree** (itself + both children).

Why does this help? Say you're searching for anything overlapping `[s, e)` and you're standing at some node's **left child**. If that left subtree's `maxEnd <= s`, that means **every single interval in that subtree ends at or before `s`** — none of them can possibly overlap `[s, e)`. So you can **skip the entire left subtree** without looking at a single node inside it.

This is exactly like a librarian who labels each shelf-section with "the latest end-date of any book on this shelf" — if you want books ending after March, and a shelf's label says "everything here ends before February," you skip the whole shelf instantly instead of checking every book on it.

This one `maxEnd` field is what turns a "check everyone" O(n) search into a "prune half the tree at every step" O(log n) search.

---

## Part 3: `Node` class

```cpp
class Node {
public:
    int id, start, end;
    int height, maxEnd;
    Node *left, *right;
};
```

Each node is one booked event. `height` is used purely for AVL balancing math. `maxEnd` is the interval-tree trick from Part 2. On creation, `height = 1` (a leaf is height 1) and `maxEnd = end` (with no children yet, the max end in its subtree is just its own end).

---

## Part 4: The small AVL helper functions

These are all little utility functions the bigger functions lean on. None of them are complicated alone — think of them as vocabulary words before you read the sentences.

### `height(node)`
Returns `node->height`, or `0` if `node` is `nullptr` (an empty tree has height 0). This null-check-first pattern repeats everywhere in this code — **always handle the "nothing here" case before touching the node**, or you'll crash on a null pointer.

### `getMaxEnd(node)`
Same idea, but returns `INT_MIN` for `nullptr`. Why `INT_MIN` and not `0`? Because we're about to `max()` this against real values — if intervals can have negative `end` values, `0` would be wrong. `INT_MIN` guarantees "an empty subtree never wins the max() comparison."

### `getBalance(node)`
```cpp
return height(node->left) - height(node->right);
```
This is *the* number the AVL tree watches. If it's `> 1`, the left side is too tall (left-heavy). If it's `< -1`, the right side is too tall. If it's between -1 and 1, the node is balanced and fine.

### `update(node)`
Called right after a node's children change (after insert/delete/rotation). Recomputes:
```cpp
node->height = 1 + max(height(left), height(right));
node->maxEnd = max(node->end, max(getMaxEnd(left), getMaxEnd(right)));
```
Intuition: "your height is one more than your taller child; your maxEnd is the biggest end-value among you and your two children." **Every function that changes the tree's shape must call `update()` afterward**, or these cached values go stale and the whole optimization breaks silently (this is the #1 bug source in interval-tree code — forgetting to update after a rotation).

### `lessThan(start1, id1, start2, id2)`
This *is* the ordering rule for the whole tree: compare by `start` first, and if tied, compare by `id`. Every insert, delete, and rotation decision routes through this one function — if you ever need to change how the tree orders events, this is the only place you'd touch.

---

## Part 5: Rotations — how the tree "fixes itself"

Rotations are the mechanical trick that keeps the tree balanced. There are two: `rightRotate` and `leftRotate`. They're mirror images of each other.

### `rightRotate(y)` — used when the tree is left-heavy

```
        y                x
       / \              / \
      x   T3    ==>    T1   y
     / \                   / \
    T1  T2                T2  T3
```

```cpp
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *z = x->right;   // "T2" in the diagram

    x->right = y;   // x becomes the new top, y becomes its right child
    y->left = z;    // y adopts x's old right subtree

    update(y);  // update y FIRST (it's now lower down)
    update(x);  // then update x (it's now higher up)

    return x;   // x is the new root of this subtree
}
```
Intuition: `x` (the left child) "rotates up" to become the new top, and `y` (old top) becomes `x`'s right child. The middle chunk (`T2`) has to move from being `x`'s right child to being `y`'s left child, because it still belongs *between* `x` and `y` in sorted order.

**Why update `y` before `x`?** Because `x`'s height/maxEnd depend on `y`'s *new, correct* values (`y` is now `x`'s child). If you updated `x` first, it would compute using `y`'s stale numbers.

### `leftRotate(x)` — the mirror image, used when right-heavy

Exact same logic, flipped left↔right. Used when the *right* side is too tall.

You'll never call these directly for a query — they're only invoked automatically inside `insertNode` / `deleteNode` when a balance check detects trouble.

---

## Part 6: `insertNode` — adding a node into the tree

```cpp
Node *insertNode(Node *node, int id, int start, int end)
```

This is a classic **recursive BST insert + AVL rebalance**, done in one pass. Walk through it like this:

1. **Base case:** if `node == nullptr`, we've found the empty spot — create and return a new `Node` here.
2. **Recurse left or right:** compare `(start, id)` against the current node using `lessThan`. Go left if smaller, right otherwise. This recursion is how the tree "walks down" to find where the new event belongs.
3. **On the way back up**, call `update(node)` — every ancestor of the new node needs its `height`/`maxEnd` refreshed, because a new descendant might change both.
4. **Check `getBalance(node)`.** If it's outside `[-1, 1]`, the tree is now unbalanced *at this node*, and we fix it with one of four rotation cases:
   - **LL** (balance > 1, new node went into left-of-left): single `rightRotate`
   - **RR** (balance < -1, new node went into right-of-right): single `leftRotate`
   - **LR** (balance > 1, new node went into left-of-right): `leftRotate` the left child first, *then* `rightRotate` — because a single rotation alone wouldn't fix a "zigzag" imbalance
   - **RL** (balance < -1, new node went into right-of-left): mirror of LR

Intuition for why there are 4 cases and not 2: imagine leaning a ladder. If it's leaning straight to one side, one push (single rotation) straightens it. But if it's leaning in an "S" shape (zigzag), one push just moves the S around — you need two pushes (double rotation) to actually straighten it.

Since this function fixes balance at **every node on the path back to the root**, after it returns, the *entire* tree is guaranteed balanced again — not just the local spot where you inserted.

---

## Part 7: `minimum(node)`

```cpp
while (current->left != nullptr) current = current->left;
```
In a BST, the smallest node in any subtree is always found by walking left as far as possible (there's nothing smaller than it, or it wouldn't be the leftmost). This is used inside delete, explained next.

---

## Part 8: `deleteNode` — removing a node, the trickiest function

```cpp
Node *deleteNode(Node *node, int start, int id)
```

Same recursive shape as insert: **find the node, remove it, rebalance on the way back up.** The subtlety is *how* you remove a node that might have 0, 1, or 2 children.

1. **Recurse to find the target**, same `lessThan`-based navigation as insert.
2. **Once found (the "else" branch), there are 3 cases:**
   - **No children:** just delete it, return `nullptr` (parent now points to nothing here).
   - **One child:** the node is redundant — just splice it out and return its single child directly upward, deleting the node itself.
   - **Two children:** this is the tricky one. You **cannot** just delete a node with two children — you'd orphan both subtrees. Instead:
     - Find its **in-order successor** — the smallest node in its *right* subtree (`minimum(node->right)`). This is the next event chronologically after the one being deleted.
     - **Copy that successor's data into the current node** (`node->id = temp->id`, etc.) — so the current node "becomes" the successor.
     - Then recursively delete the *original* successor node from the right subtree (which is now guaranteed to have at most one child, so it falls into an easier case).

   Intuition: you can't remove a node with two children directly without breaking the tree, so instead you "swap" its identity with the next-smallest node, then delete that easier node instead. It's like removing a person from the middle of a queue by having the next person shuffle forward into their spot, then removing the (now-duplicate) person from the back.

3. **Same rebalancing as insert on the way back up**, but the balance-checking condition is slightly different (uses `getBalance(node->left) >= 0` instead of comparing new-vs-old start/id) — because deletion doesn't have a "new node" to compare against; it just needs to know which way the *existing* subtree currently leans.

---

## Part 9: `treeString(node)` — for debugging/output, not required for correctness

```cpp
return to_string(node->id) + "(" + treeString(left) + "," + treeString(right) + ")";
```
Prints the tree as nested `id(left,right)` — e.g. `5(3(,),8(,))`. This exists purely so the program can print the tree's exact shape after every `ADD`/`UPDATE`, which is how your output file gets checked against the expected output — it's essentially a fingerprint of the tree's exact structure (not just its contents), which catches bugs in rotations that a plain "list of events" output wouldn't catch.

---

## Part 10: The search functions — where `maxEnd` actually pays off

All four follow the same skeleton: *"check if the left subtree could possibly matter (using maxEnd), check myself, then decide whether the right subtree could possibly matter."*

### `conflictSearch(node, s, e)` — "does anything overlap `[s, e)`?"

```cpp
if (node->left != nullptr && node->left->maxEnd > s) {
    if (conflictSearch(node->left, s, e)) return true;
}
if (node->start < e && s < node->end) return true;   // standard interval-overlap test
if (node->start >= e) return false;   // prune: nothing further right can overlap
return conflictSearch(node->right, s, e);
```

Three things happening:
1. **Prune left?** Only recurse left if `left->maxEnd > s` — otherwise (per Part 2's librarian analogy) nothing on the left could possibly end after `s`, so it can't overlap.
2. **Check self:** the classic two-interval-overlap condition `start < e && s < end` — two intervals overlap unless one entirely ends before the other starts.
3. **Prune right?** Because the tree is sorted by `start`, if this node's own `start >= e`, then *every* node to the right (which all have `start >= this node's start`) also starts at or after `e` — meaning they start after your query even ends, so none of them can overlap either. Stop early.

This is why the function is O(log n) instead of O(n): at every node, it's throwing away roughly half the remaining tree, either via the `maxEnd` prune or the `start >= e` prune.

### `overlapsSearch(node, s, e, result)`

Identical logic to `conflictSearch`, except instead of returning `true` on the first match, it **appends** the id to `result` and **keeps searching** (since we want *all* overlaps, not just proof that one exists). Same pruning rules apply on both sides.

### `atSearch(node, t, result)` — "what's active exactly at time `t`?"

Same shape, but the overlap condition becomes `start <= t && t < end` (a single point in time, not a range) — and the right-side prune condition becomes `node->start > t` instead of `>= e`, since we're comparing against a single time point instead of a range's end.

### `nextSearch(node, t)` — "what's the next event starting at or after `t`?"

This one is **not recursive** — it's a plain iterative BST walk, which is a nice simplification worth noticing:
```cpp
while (node != nullptr) {
    if (node->start >= t) { candidate = node; node = node->left; }
    else { node = node->right; }
}
```
Intuition: this is the classic "find the smallest value `>= t`" pattern. Every time you find a node whose `start >= t`, it's a *candidate* answer — but there might be an even smaller one further left, so you keep going left, remembering the best candidate so far. Every time a node's `start < t`, it's too early, so you go right to look for something later. When you fall off the tree (`node == nullptr`), whatever you last remembered is the answer.

---

## Part 11: `clear(node)` — destructor cleanup

```cpp
void clear(Node *node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
```
A post-order traversal (children before self) that frees every node. Needed because this code uses raw pointers (`new Node(...)`), so without this, deleting the `IntervalScheduler` object would leak all the tree's memory. This runs automatically via `~IntervalScheduler()` when the scheduler goes out of scope.

---

## Part 12: The public API — the "front desk" of the class

These are thin wrappers that connect the outside world (your `main()`, reading commands from a file) to the internal tree functions. They also maintain a second data structure:

```cpp
unordered_map<int, pair<int, int>> events;   // id -> (start, end)
```

**Why keep this separate hash map at all, if the AVL tree already stores everything?**
Because the AVL tree is sorted by `(start, id)` — if you're given just an `id` (like in `REMOVE id` or `UPDATE id s e`), you have **no way to find that node's `start`** without this lookup, and without the `start` you can't navigate the tree (since it's sorted by `start`, not `id`). The hash map gives O(1) `id -> start` lookup, which is what lets `REMOVE`/`UPDATE` locate the right tree node in the first place before doing the actual O(log n) tree operation.

- **`add(s, e)`**: assigns the next auto-incrementing `id`, inserts into the tree, records it in `events`, returns the new `id`.
- **`remove(id)`**: looks up `id` in `events` to get its `start` (see above), deletes that node from the tree, erases it from `events`. Returns `false` if the `id` never existed.
- **`updateEvent(id, s, e)`**: this is implemented as **delete + re-insert**, not an in-place edit. Why? Because the tree is sorted by `start` — if you changed a node's `start` in place without moving it, the tree's ordering invariant would break (nodes could end up on the wrong side of an ancestor). Delete-then-reinsert is the safe way to "move" a node to a new sorted position.
- **`conflict` / `overlaps` / `at` / `next`**: thin pass-throughs to the corresponding `*Search` functions on `root`.

---

## Part 13: `main()` and what the timing report actually means

### The parsing loop
`main()` reads commands one at a time from the input file (`ADD`, `REMOVE`, `UPDATE`, `CONFLICT`, `OVERLAPS`, `AT`, `NEXT`), and for each one:
1. Records a timestamp (`steady_clock::now()`)
2. Calls the matching scheduler function
3. Records another timestamp
4. Computes the difference in **nanoseconds** and adds it to a running total for that command type
5. Writes the result to the output file

### What is `steady_clock`, and why not just use a regular clock?
`steady_clock` is a monotonic clock — it only ever moves forward, and isn't affected by the system clock being adjusted (NTP sync, daylight savings, etc.). For measuring *how long code took to run*, you always want a steady/monotonic clock, never wall-clock time, because wall-clock time can jump backward or forward for reasons that have nothing to do with your program's speed.

### What the timing report is actually telling you
```
Operation      Count      Total (ns)      Avg (ns)
add              950          206593           217
```
This says: 950 `ADD` operations were performed, taking 206,593 nanoseconds combined, averaging 217 ns each.

**Why does this matter conceptually?** Because it's an *empirical* check on the AVL tree's theoretical guarantee. Since every operation here is O(log n), and `log2(950) ≈ 10`, you'd expect each operation to do roughly "10 units of work" regardless of how large the tree gets. If you doubled the number of events to ~1900, `log2(1900) ≈ 11` — barely more work per operation. **This is the entire point of using an AVL tree**: a plain array/list would show average time growing *linearly* with the number of events (O(n) per op), while this tree should show average time growing *barely at all* (O(log n) per op) even as the dataset gets much bigger. If you ever wanted to prove the AVL tree is working correctly in a viva, you'd run this same program on a much bigger test file and show the average-ns-per-op barely increases — that's a live demonstration of O(log n) vs O(n).

**Why time each operation type separately** (add vs remove vs conflict, etc.) rather than one overall total? Because they're not doing the same amount of work — `NEXT` is a single iterative walk down the tree, while `OVERLAPS` might visit and collect many matching nodes. Separating them lets you sanity-check each operation's cost independently, rather than one number hiding very different behaviors.

---

## Part 14: The one-sentence summary for each function (cheat sheet)

| Function | One-line purpose |
|---|---|
| `height` | Safe height lookup (0 for null) |
| `getMaxEnd` | Safe maxEnd lookup (-∞ for null) |
| `getBalance` | left height − right height |
| `update` | Recompute height & maxEnd from children |
| `lessThan` | The tree's ordering rule: (start, id) |
| `rightRotate` / `leftRotate` | Mechanically fix a lopsided subtree |
| `insertNode` | BST insert + rebalance on the way back up |
| `minimum` | Walk left to find the smallest node |
| `deleteNode` | BST delete (3 cases) + rebalance |
| `treeString` | Debug/output: print tree shape as text |
| `conflictSearch` | "Does anything overlap [s,e)?" — prune with maxEnd |
| `overlapsSearch` | "What overlaps [s,e)?" — same pruning, collects all |
| `atSearch` | "What's active at time t?" — point-in-time version |
| `nextSearch` | Iterative: smallest start ≥ t |
| `clear` | Free all nodes (destructor) |
| `add / remove / updateEvent` | Public API: mutate tree + keep `events` map in sync |
| `conflict / overlaps / at / next` | Public API: thin wrappers around the `*Search` functions |
| `main()` | Parse commands, time each op, write results, print report |

---

## How to explain this to someone in 60 seconds (elevator pitch)

*"It's an AVL tree — a self-balancing binary search tree — sorted by event start time, and each node additionally tracks the maximum end-time in its subtree. That one extra field lets overlap queries skip entire branches of the tree that can't possibly contain a match, which is what makes conflict-checking O(log n) instead of checking every event one by one. Insert and delete work like a normal BST insert/delete, but after every change we walk back up and rotate nodes as needed to keep the tree balanced, so it never degrades into a slow linked-list shape."*