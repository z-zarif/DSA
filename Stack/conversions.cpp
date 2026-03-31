#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
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
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
string reverseAndSwap(string s)
{
    reverse(s.begin(), s.end());
    for (char &c : s)
    {
        if (c == '(')
            c = ')';
        if (c == ')')
            c = '(';
    }
    return s;
}
string infixToPrefix(string s)
{
    string rev = reverseAndSwap(s);
    string prfix= infixToPostfix(rev);
    reverse(prfix.begin(), prfix.end());
    return prfix;
}
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    }
    return 0;
}
int evaluatePostfix(string exp)
{
    stack<int> st;
    for (char c : exp)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            st.push(applyOp(a, b, c));
        }
    }
    return st.top();
}
int evaluatePrefix(string exp)
{
    stack<int> st;
    for (int i = exp.size() - 1; i >= 0; i--)
    {
        char c = exp[i];
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(applyOp(a, b, c));
        }
    }
    return st.top();
}

int main()
{
    fastIO();
        string infix = "A+B*C";
    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Infix   : " << infix << endl;
    cout << "Postfix : " << postfix << endl;
    cout << "Prefix  : " << prefix << endl;

    // Evaluation (only for digits)
    string postExp = "234*+";
    string preExp  = "+2*34";

    cout << "\nPostfix Evaluation: " << evaluatePostfix(postExp) << endl;
    cout << "Prefix Evaluation : " << evaluatePrefix(preExp) << endl;


    return 0;
}