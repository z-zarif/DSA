#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    };
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = nullptr;
    };
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    void pop_back()
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "invalid" << endl;
        }
        else if (pos == 0)
        {
            push_front(val);
        }
        else
        {
            Node *newNode = new Node(val);
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}