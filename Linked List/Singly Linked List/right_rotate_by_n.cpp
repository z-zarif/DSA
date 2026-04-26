#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
};
Node *rightrotate(Node *head, int k)
{
    Node *temp = head;
    int L = 1;
    while (temp != nullptr)
    {
        temp = temp->next;
        L++;
    }
    Node *temp2 = head;
    k = k % L;
    if (k == 0)
        return head;
    for (int i = 0; i < L - k; i++)
    {
        temp2 = temp2->next;
    }
    Node *newTail = temp2;
    Node *oldHead = head;
    head = newTail->next;
    newTail->next=nullptr;
    temp->next=oldHead;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        if (node->next != NULL)
        {
            cout << "-> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = rightrotate(head, 6);
    printList(head);
    return 0;
}