#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    };
};
class Doublylist
{
private:
    Node *head;
    Node *tail;

public:
    Doublylist()
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
            head->prev = newNode;
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "the list is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            head->prev = nullptr;
            delete temp;
        }
    }
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "the list is empty" << endl;
            return;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            temp->prev = nullptr;
            delete temp;
        }
    }
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}