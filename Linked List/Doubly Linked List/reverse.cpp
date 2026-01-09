#include <bits/stdc++.h>
using namespace std;
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
    Node *reverse(Node *head)
    {
        Node *cur;
        Node *nextnode;
        cur = head;
        if (head == nullptr)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            while (cur != nullptr)
            {
                nextnode = cur->next;
                cur->next = cur->prev;
                cur->prev = nextnode;
                cur = nextnode;
            }
        }
    }
};