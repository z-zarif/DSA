#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        next = prev = nullptr;
    };
    ~node();
};
class DLL
{
private:
    node *head;
    node *tail;

public:
    DLL()
    {
        head = tail = nullptr;
    };
    node *createfromarray(int arr[], int n)
    {
        head = new node(arr[0]);
        node *temp = head;
        for (int i = 1; i < n; i++)
        {
            node *curr = new node(arr[i]);
            curr->prev = temp;
            curr->next = nullptr;
            temp = curr;
        }
        return head;
    }
    void push_front(int val)
    {
        node *newnode = new node(val);
        newnode->next = head;
        newnode->prev = nullptr;
        head = newnode;
    };
    void popfront()
    {
        node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    };
    void push_back(int val)
    {
        node *newnode = new node(val);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    void insertatidx(int idx,int val)
    {
       node*newnode=new node(val);
        node*temp=head;
        for (int i = 0; i < idx; i++)
        {
            temp=temp->next;
        }
        temp->next->prev=newnode;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        
        
        
    }
    void removeatidx(int idx)
    {
        node*temp=head;
        for (int i = 0; i < idx; i++)
        {
            temp=temp->next;
        }
        node*del=temp->next;
        temp->next=del->next;
        del->next->prev=temp;
        del->next=nullptr;
        del->prev=nullptr;
        delete del;

        
    }
    ~DLL();
};

DLL::DLL(/* args */)
{
}

DLL::~DLL()
{
}

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fastIO();

    return 0;
}