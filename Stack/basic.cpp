// follows the principle of LIFO
// LIFO- last in first out
// stack has three important function
// push, pop, top- must happen in O(1) time complexity

//!STACK USING VECTOR
#include <bits/stdc++.h>
using namespace std;
// class Stack
// {
// private:
//     vector<int> v;

// public:
//     void push(int val)
//     {
//         v.push_back(val);
//     }
//     void pop()
//     {
//         v.pop_back();
//     }
//     int top()
//     {
//         return v[v.size() - 1];
//     }
//     bool empty(){
//         return v.size()==0;
//     }
// };



 
//!STACK USING LINKED LIST
class Stack
{
private:
    list<int>ll;
public:
    void push(int val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        ll.pop_front();
    }
    int top()
    {
        return ll.front();
    }
    bool empty(){
        return ll.size()==0;
    }
};


int main(int argc, char const *argv[])
{
    Stack s;
    s.push(10);
    s.push(40);
    s.push(60);
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}


