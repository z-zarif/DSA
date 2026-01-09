// FIFO- first in, first out
// push- from the rear// also known as enqueue
// pop- from the front// also known as dueque (//!not deque, it is double ended queue)
#include <bits/stdc++.h>
using namespace std;
//! using stl linked list
// class queue
// {
// private:
//     list<int> ll;

// public:
//     void push(int val)
//     {
//         ll.push_back(val);
//     }
//     void pop()
//     {
//         ll.pop_front();
//     }
//     int front()
//     {
//         return ll.front();
//     }
// };

//! Creating my own Node
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue(/* args */)
    {
        head = tail = nullptr;
    };
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {

            tail->next = newNode;
            // newNode->next = nullptr;
            tail = newNode;
        }
    }
    void pop()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (!head)
        {
            tail = nullptr;
        }
        // temp->next = nullptr; //*not necessary
        delete temp;
    }
    int front()
    {
        return head->data;
    }
    bool empty()
    {
        return head == nullptr;
    }
};
int main(int argc, char const *argv[])
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
