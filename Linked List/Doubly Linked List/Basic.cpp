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
    void insert(int val, int idx)
    {
        if (idx < 0)
        {
            cout << "invalid index" << endl;
        }
        else if (idx == 0)
        {
            push_front(val);
            return;
        }

        else
        {
            Node *newNode = new Node(val);
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            if (temp->next == nullptr)
            {
                push_back(val);
                return;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    void delete_at_idx(int idx)
    {
        if (idx == 0)
        {
            pop_front();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            return;
        }
        temp->prev->next = temp->next;
        if (temp != tail)
        {
            temp->next->prev = temp->prev;
        }
        else
            tail = temp->prev;
        delete temp;
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