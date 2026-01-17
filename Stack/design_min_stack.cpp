// all functions of stack and with the getmin function, that gives you minimum of current values of stack
#include <bits/stdc++.h>
using namespace std;

//! Easier and much more intuitive solution
// class SpecialStack
// {
// private:
//     stack<int> st;
//     stack<int> minStack;

// public:
//     void push(int a)
//     {
//         st.push(a);
//         if (minStack.empty() || a < minStack.top())
//         {
//             minStack.push(a);
//         }
//         else
//             minStack.push(minStack.top());
//     }
//     void pop()
//     {
//         st.pop();
//         minStack.pop();
//     }
//      int top()
//      {
//       return st.top();
//       }
//     int getMin()
//     {
//         return minStack.top();
//     }
//     bool empty()
//     {
//         return st.size() == 0;
//     }
// };

//! Using a PairStack;
class SpecialStack
{
private:
    stack<pair<int, int>> st;

public:
    void push(int a)
    {
        if (st.empty())
        {
            st.push({a, a});
        }
        else
        {
            int minVal = min(a, st.top().second);
            st.push({a, minVal});
        }
    }
    void pop()
    {
        st.pop();
    }
    int top()
    {
        return st.top().first;
    }
    int getMin()
    {
        return st.top().second;
    }
    bool empty()
    {
        return st.size() == 0;
    }
};

int main(int argc, char const *argv[])
{
    SpecialStack st;

    st.push(18);
    st.push(19);
    st.push(29);
    st.push(15);
    st.push(16);

    cout << st.getMin() << endl;

    return 0;
}
