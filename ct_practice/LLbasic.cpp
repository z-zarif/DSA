#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)

    {
        data = val;
        next = nullptr;
    };
    // ~Node();
};
class SLL
{
private:
    Node *head;
    Node *tail;

public:
    SLL(/* args */)
    {
        head = tail = nullptr;
    };
    void push_front(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    void push_back(int val)
    {
        Node *temp = new Node(val);
        if (!head)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void pop_front()
    {
        if (!head)
        {
            return;
        }
        
        Node*temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
    }
    Node* insertatidx(int idx,int val)
    {
        Node* curr=new Node(val);
        Node*temp=head;
        for (int i = 0; i < idx; i++)
        {
            temp=temp->next;
        }
        curr->next=temp->next;
        temp->next=curr;
        
        
    }
    
    ~SLL();
};
Node *createLLfromarray(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    //  Node*tail= new Node(arr[n-1]);
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        Node *curr = new Node(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    return head;
}

int main()
{
    fastIO();
    SLL s1;

    return 0;
}