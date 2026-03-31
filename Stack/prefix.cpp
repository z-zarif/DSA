#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
bool isOperand(char ch)
{
    return isalnum(ch);
}
string infixToPostfix(string s)
{
    string result;
    stack<char> st;
    for (char c : s)
    {
        if (isOperand(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty()&&precedence(st.top())>=precedence(c))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
            
        }
        while (!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        
    }
}
int main()
{
    fastIO();

    return 0;
}