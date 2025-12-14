
// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->child != nullptr)
            {
                // flatten the child nodes
                Node *nexttocurr = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                // find tail
                while (curr->next != nullptr)
                {
                    curr = curr->next;
                }
                // attach tail with next ptr
                if (nexttocurr != nullptr)
                {
                    curr->next = nexttocurr;
                    nexttocurr->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};