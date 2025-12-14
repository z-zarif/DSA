// two things, one data and a nextptr. pointing to the second node
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
    //~Node();
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
    void push_front(int val)//O(1)
    {
        Node *newNode = new Node(val);
        // ektu confusing, but basically,
        // new Node(val); --> creates a node and initializes it's value
        // newnode is a pointer to the class nocde and it is pointing to the object
        // created by newNode(val)
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            // the pointer of the new pushed value will be point towards head
            // in order to establish a connection
            head = newNode;
            // then we update the head to point to newnode in order
            // to make it in the front
        }
    }
    void push_back(int val)//O(1)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()// O(1)
    {
        if (head == nullptr)
        {
            cout << "the list is empty" << endl;
            return;
        }

        // first we store the value we want to delete in temp
        Node *temp = head;
        // then we change the head to the next node;
        head = head->next;
        // then we delete the connection between the temp and rest of LL
        temp->next = nullptr;
        // then we delete the temp
        delete temp;
    }
    void pop_back()//O(n)
    {
        if (head == nullptr)
        {
            cout << "the list is empty" << endl;
            return;
        }
        Node *temp = head;
        // we can traverse LL in only one way
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = nullptr;
        delete tail;
        // we have to delete the previous tail, nahole there is a memory leak issue.
        tail = temp;
    }
    void insert(int val, int pos)//O(n)
    {
        if (pos < 0)
        {
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
            return;
        }
        else
        {
            Node *newNode = new Node(val);
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                if (temp == nullptr)
                {
                    cout << "invalid position" << endl;
                    return;
                }

                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    int search(int key)//O(n)
    {
        Node *temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return i;
            }
            i++;
            temp = temp->next;
        }
        return -1;
    }
    void display()//O(n)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        /*Go to the node that temp is pointing to
         Access its next member
        That member is another address (or nullptr)*/

        /*How does it “know” where to go next?
        It doesn’t magically know —
        you already told it earlier when building the list.*/
        cout << "NULL" << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    List ll;
    ll.push_front(3);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(7);
    ll.push_front(8);
    ll.push_front(9);
    ll.display();
    ll.pop_back();
    ll.pop_front();
    ll.display();
    ll.insert(4, 2);
    ll.display();
    cout << ll.search(7) << endl;
    return 0;
}