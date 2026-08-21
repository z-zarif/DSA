#include <bits/stdc++.h>
using namespace std;
using namespace chrono;


class Node
{
public:
    int id;
    int start;
    int end;

    int height;
    int maxEnd;

    Node *left;
    Node *right;

    Node(int id, int start, int end)
    {
        this->id = id;
        this->start = start;
        this->end = end;

        height = 1;
        maxEnd = end;

        left = nullptr;
        right = nullptr;
    }
};



class IntervalScheduler
{
private:
    Node *root;

    int nextId;




    int height(Node *node)
    {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    int getMaxEnd(Node *node)
    {
        if (node == nullptr)
            return INT_MIN;

        return node->maxEnd;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;

        return height(node->left) - height(node->right);
    }

    void update(Node *node)
    {
        if (node == nullptr)
            return;

        node->height =
            1 + max(height(node->left),
                    height(node->right));

        node->maxEnd =
            max(node->end,
                max(getMaxEnd(node->left),
                    getMaxEnd(node->right)));
    }


    /* -----------------------------------------------------
       COMPARISON BY (start, id)
       ----------------------------------------------------- */

    bool lessThan(int start1, int id1,
                  int start2, int id2)
    {
        if (start1 != start2)
            return start1 < start2;

        return id1 < id2;
    }


    /* -----------------------------------------------------
       ROTATIONS
       ----------------------------------------------------- */

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *z = x->right;

        x->right = y;
        y->left = z;

        update(y);
        update(x);

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *z = y->left;

        y->left = x;
        x->right = z;

        update(x);
        update(y);

        return y;
    }


    /* -----------------------------------------------------
       INSERT
       ----------------------------------------------------- */

    Node *insertNode(Node *node,
                     int id,
                     int start,
                     int end)
    {
        if (node == nullptr)
            return new Node(id, start, end);

        if (lessThan(start, id,
                     node->start, node->id))
        {
            node->left =
                insertNode(node->left,
                           id, start, end);
        }
        else
        {
            node->right =
                insertNode(node->right,
                           id, start, end);
        }

        update(node);

        int balance = getBalance(node);

        // LL
        if (balance > 1 &&
            lessThan(start, id,
                     node->left->start,
                     node->left->id))
        {
            return rightRotate(node);
        }

        // RR
        if (balance < -1 &&
            lessThan(node->right->start,
                     node->right->id,
                     start, id))
        {
            return leftRotate(node);
        }

        // LR
        if (balance > 1 &&
            lessThan(node->left->start,
                     node->left->id,
                     start, id))
        {
            node->left =
                leftRotate(node->left);

            return rightRotate(node);
        }

        // RL
        if (balance < -1 &&
            lessThan(start, id,
                     node->right->start,
                     node->right->id))
        {
            node->right =
                rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }


    /* -----------------------------------------------------
       FIND MINIMUM
       ----------------------------------------------------- */

    Node *minimum(Node *node)
    {
        Node *current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }


    /* -----------------------------------------------------
       DELETE
       ----------------------------------------------------- */

    Node *deleteNode(Node *node,
                     int start,
                     int id)
    {
        if (node == nullptr)
            return nullptr;

        if (lessThan(start, id,
                     node->start, node->id))
        {
            node->left =
                deleteNode(node->left,
                           start, id);
        }
        else if (lessThan(node->start,
                          node->id,
                          start, id))
        {
            node->right =
                deleteNode(node->right,
                           start, id);
        }
        else
        {
            // No child
            if (node->left == nullptr &&
                node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Only right child
            if (node->left == nullptr)
            {
                Node *temp = node->right;

                delete node;

                return temp;
            }

            // Only left child
            if (node->right == nullptr)
            {
                Node *temp = node->left;

                delete node;

                return temp;
            }

            // Two children
            Node *temp = minimum(node->right);

            node->id = temp->id;
            node->start = temp->start;
            node->end = temp->end;

            node->right =
                deleteNode(node->right,
                           temp->start,
                           temp->id);
        }

        update(node);

        int balance = getBalance(node);

        // LL
        if (balance > 1 &&
            getBalance(node->left) >= 0)
        {
            return rightRotate(node);
        }

        // LR
        if (balance > 1 &&
            getBalance(node->left) < 0)
        {
            node->left =
                leftRotate(node->left);

            return rightRotate(node);
        }

        // RR
        if (balance < -1 &&
            getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }

        // RL
        if (balance < -1 &&
            getBalance(node->right) > 0)
        {
            node->right =
                rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }


    /* -----------------------------------------------------
       FIND EVENT BY ID
       ----------------------------------------------------- */

    unordered_map<int, pair<int, int>> events;


    /* -----------------------------------------------------
       NESTED TREE REPRESENTATION
       ----------------------------------------------------- */

    string treeString(Node *node)
    {
        if (node == nullptr)
            return "";

        if (node->left == nullptr &&
            node->right == nullptr)
        {
            return to_string(node->id);
        }

        return to_string(node->id) +
               "(" +
               treeString(node->left) +
               "," +
               treeString(node->right) +
               ")";
    }


    /* -----------------------------------------------------
       CONFLICT SEARCH
       
       Find ANY interval overlapping [s,e)
       ----------------------------------------------------- */

    bool conflictSearch(Node *node,
                        int s,
                        int e)
    {
        if (node == nullptr)
            return false;

        // If left subtree cannot contain an overlap,
        // don't visit it.
        if (node->left != nullptr &&
            node->left->maxEnd > s)
        {
            if (conflictSearch(node->left, s, e))
                return true;
        }

        // Check current node
        if (node->start < e &&
            s < node->end)
        {
            return true;
        }

        // Since tree is ordered by start,
        // if current start >= e,
        // everything in right subtree starts >= e.
        if (node->start >= e)
            return false;

        return conflictSearch(node->right, s, e);
    }


    /* -----------------------------------------------------
       OVERLAPS
       ----------------------------------------------------- */

    void overlapsSearch(Node *node,
                        int s,
                        int e,
                        vector<int> &result)
    {
        if (node == nullptr)
            return;

        /*
           Left subtree can only contain overlap if
           some interval there ends after s.
        */
        if (node->left != nullptr &&
            node->left->maxEnd > s)
        {
            overlapsSearch(node->left,
                           s, e, result);
        }

        // Current node
        if (node->start < e &&
            s < node->end)
        {
            result.push_back(node->id);
        }

        /*
           If current start >= e,
           every node in right subtree also has
           start >= e, so stop.
        */
        if (node->start >= e)
            return;

        overlapsSearch(node->right,
                       s, e, result);
    }


    /* -----------------------------------------------------
       AT t
       Find all intervals satisfying

             start <= t < end
       ----------------------------------------------------- */

    void atSearch(Node *node,
                  int t,
                  vector<int> &result)
    {
        if (node == nullptr)
            return;

        /*
           Left subtree can contain intervals
           active at t only if maxEnd > t.
        */
        if (node->left != nullptr &&
            node->left->maxEnd > t)
        {
            atSearch(node->left,
                     t, result);
        }

        if (node->start <= t &&
            t < node->end)
        {
            result.push_back(node->id);
        }

        /*
           If current start > t,
           all nodes in right subtree have
           start > t, so they cannot contain
           an interval satisfying start <= t.
        */
        if (node->start > t)
            return;

        atSearch(node->right,
                 t, result);
    }


    /* -----------------------------------------------------
       NEXT
       
       Smallest (start,id) where start >= t
       ----------------------------------------------------- */

    Node *nextSearch(Node *node,
                     int t)
    {
        Node *candidate = nullptr;

        while (node != nullptr)
        {
            if (node->start >= t)
            {
                candidate = node;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        return candidate;
    }


    /* -----------------------------------------------------
       MEMORY CLEANUP
       ----------------------------------------------------- */

    void clear(Node *node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);

        delete node;
    }


public:

    IntervalScheduler()
    {
        root = nullptr;
        nextId = 1;
    }

    ~IntervalScheduler()
    {
        clear(root);
    }


    /* =====================================================
       REQUIRED OPERATIONS
       ===================================================== */


    // ADD
    int add(int s, int e)
    {
        int id = nextId++;

        root = insertNode(root,
                          id,
                          s,
                          e);

        events[id] = {s, e};

        return id;
    }


    // REMOVE
    bool remove(int id)
    {
        auto it = events.find(id);

        if (it == events.end())
            return false;

        int s = it->second.first;

        root = deleteNode(root,
                          s,
                          id);

        events.erase(it);

        return true;
    }


    // UPDATE
    bool updateEvent(int id,
                     int s,
                     int e)
    {
        auto it = events.find(id);

        if (it == events.end())
            return false;

        int oldStart = it->second.first;

        root = deleteNode(root,
                          oldStart,
                          id);

        root = insertNode(root,
                          id,
                          s,
                          e);

        it->second = {s, e};

        return true;
    }


    // CONFLICT
    bool conflict(int s, int e)
    {
        return conflictSearch(root, s, e);
    }


    // OVERLAPS
    vector<int> overlaps(int s, int e)
    {
        vector<int> result;

        overlapsSearch(root,
                       s, e,
                       result);

        return result;
    }


    // AT
    vector<int> at(int t)
    {
        vector<int> result;

        atSearch(root,
                 t,
                 result);

        return result;
    }


    // NEXT
    bool next(int t,
              int &id,
              int &s,
              int &e)
    {
        Node *node = nextSearch(root, t);

        if (node == nullptr)
            return false;

        id = node->id;
        s = node->start;
        e = node->end;

        return true;
    }


    string toString()
    {
        return treeString(root);
    }
};


/* =========================================================
   PRINT VECTOR
   ========================================================= */

void printIDs(ofstream &out,
              const vector<int> &v)
{
    if (v.empty())
    {
        out << "none\n";
        return;
    }

    for (int i = 0; i < (int)v.size(); i++)
    {
        if (i > 0)
            out << " ";

        out << v[i];
    }

    out << '\n';
}


/* =========================================================
   MAIN
   ========================================================= */

int main(int argc, char *argv[])
{
    IntervalScheduler scheduler;

    // Input file: pass as first command-line arg (e.g. ./avl large.txt)
    // Falls back to "large.txt" if no argument is given.
    string inputPath = (argc > 1) ? argv[1] : "large.txt";

    // Output file: derived from the input file name, e.g.
    // "large.txt" -> "large_output.txt". Can be overridden with a
    // second command-line arg (e.g. ./avl large.txt myoutput.txt).
    string outputPath;

    if (argc > 2)
    {
        outputPath = argv[2];
    }
    else
    {
        size_t dot = inputPath.find_last_of('.');

        string base = (dot == string::npos)
                          ? inputPath
                          : inputPath.substr(0, dot);

        outputPath = base + "_output.txt";
    }

    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    if (!inputFile)
    {
        cerr << "Could not open " << inputPath << "\n";
        return 1;
    }

    if (!outputFile)
    {
        cerr << "Could not create " << outputPath << "\n";
        return 1;
    }


    /*
       Timing variables

       We store:
       add
       remove
       update
       conflict
       overlaps
       at
       next
    */

    long long addCount = 0;
    long long addTotal = 0;

    long long removeCount = 0;
    long long removeTotal = 0;

    long long updateCount = 0;
    long long updateTotal = 0;

    long long conflictCount = 0;
    long long conflictTotal = 0;

    long long overlapsCount = 0;
    long long overlapsTotal = 0;

    long long atCount = 0;
    long long atTotal = 0;

    long long nextCount = 0;
    long long nextTotal = 0;


    string command;

    while (inputFile >> command)
    {
        if (command == "ADD")
        {
            int s, e;

            inputFile >> s >> e;

            auto startTime = steady_clock::now();

            int id = scheduler.add(s, e);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            addCount++;
            addTotal += duration;

            outputFile << scheduler.toString() << '\n';
        }

        else if (command == "REMOVE")
        {
            int id;

            inputFile >> id;

            auto startTime = steady_clock::now();

            bool success =
                scheduler.remove(id);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            removeCount++;
            removeTotal += duration;

            if (success)
                outputFile << scheduler.toString() << '\n';
            else
                outputFile << "not found\n";
        }

        else if (command == "UPDATE")
        {
            int id, s, e;

            inputFile >> id >> s >> e;

            auto startTime = steady_clock::now();

            bool success =
                scheduler.updateEvent(id, s, e);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            updateCount++;
            updateTotal += duration;

            if (success)
                outputFile << scheduler.toString() << '\n';
            else
                outputFile << "not found\n";
        }

        else if (command == "CONFLICT")
        {
            int s, e;

            inputFile >> s >> e;

            auto startTime = steady_clock::now();

            bool result =
                scheduler.conflict(s, e);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            conflictCount++;
            conflictTotal += duration;

            outputFile << (result ? "yes\n" : "no\n");
        }

        else if (command == "OVERLAPS")
        {
            int s, e;

            inputFile >> s >> e;

            auto startTime = steady_clock::now();

            vector<int> result =
                scheduler.overlaps(s, e);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            overlapsCount++;
            overlapsTotal += duration;

            printIDs(outputFile, result);
        }

        else if (command == "AT")
        {
            int t;

            inputFile >> t;

            auto startTime = steady_clock::now();

            vector<int> result =
                scheduler.at(t);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            atCount++;
            atTotal += duration;

            printIDs(outputFile, result);
        }

        else if (command == "NEXT")
        {
            int t;

            inputFile >> t;

            int id, s, e;

            auto startTime = steady_clock::now();

            bool found =
                scheduler.next(t, id, s, e);

            auto endTime = steady_clock::now();

            long long duration =
                duration_cast<nanoseconds>
                (endTime - startTime).count();

            nextCount++;
            nextTotal += duration;

            if (found)
            {
                outputFile
                    << id << " "
                    << s << " "
                    << e << '\n';
            }
            else
            {
                outputFile << "none\n";
            }
        }
    }


    inputFile.close();
    outputFile.close();


    /* =====================================================
       TIMING SUMMARY
       ===================================================== */

    struct Row
    {
        string name;
        long long count;
        long long totalNs;
    };

    vector<Row> rows = {
        {"add",      addCount,      addTotal},
        {"remove",   removeCount,   removeTotal},
        {"update",   updateCount,   updateTotal},
        {"conflict", conflictCount, conflictTotal},
        {"overlaps", overlapsCount, overlapsTotal},
        {"at",       atCount,       atTotal},
        {"next",     nextCount,     nextTotal},
    };

    long long grandCount = 0;
    long long grandTotal = 0;

    for (const auto &r : rows)
    {
        grandCount += r.count;
        grandTotal += r.totalNs;
    }

    const int wOp    = 10;
    const int wCount = 10;
    const int wTotal = 16;
    const int wAvg   = 14;
    const int lineLen = wOp + wCount + wTotal + wAvg;

    cout << "\n";
    cout << string(lineLen, '=') << "\n";
    cout << "  INTERVAL SCHEDULER - TIMING REPORT\n";
    cout << string(lineLen, '=') << "\n";

    cout << left  << setw(wOp)    << "Operation"
         << right << setw(wCount) << "Count"
         << right << setw(wTotal) << "Total (ns)"
         << right << setw(wAvg)   << "Avg (ns)"
         << "\n";

    cout << string(lineLen, '-') << "\n";

    for (const auto &r : rows)
    {
        cout << left  << setw(wOp)    << r.name
             << right << setw(wCount) << r.count
             << right << setw(wTotal) << r.totalNs
             << right << setw(wAvg);

        if (r.count == 0)
            cout << "N/A";
        else
            cout << (r.totalNs / r.count);

        cout << "\n";
    }

    cout << string(lineLen, '-') << "\n";

    cout << left  << setw(wOp)    << "TOTAL"
         << right << setw(wCount) << grandCount
         << right << setw(wTotal) << grandTotal
         << right << setw(wAvg);

    if (grandCount == 0)
        cout << "N/A";
    else
        cout << (grandTotal / grandCount);

    cout << "\n";

    cout << string(lineLen, '=') << "\n";

    cout << "Input file  : " << inputPath  << "\n";
    cout << "Output file : " << outputPath << "\n";
    cout << string(lineLen, '=') << "\n";

    return 0;
}