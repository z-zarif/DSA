#include <bits/stdc++.h>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }

    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}
string infixToPostfix(string infix)
{
    stack<char> s1;
    int n = infix.length();
    string postfix;
    for (int i = 0; i < n; i++)
    {
        char ch = infix[i];
        if (ch == ' ')
        {

            continue;
        }
        else if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s1.push(ch);
        }
        else if (ch == ')')
        {
            while (!s1.empty() && s1.top() != '(')
            {
                postfix += s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else if (isOperator(ch))
        {
            while (!s1.empty() && s1.top() != '(' && precedence(s1.top()) >= precedence(ch))
            {
                postfix += s1.top();
                s1.pop();
            }
            s1.push(ch);
        }
    }
    while (!s1.empty())
    {
        postfix += s1.top();
        s1.pop();
    }

    return postfix;
}

int main()
{
    cout << "=== Infix to Postfix Conversion ===" << endl
         << endl;

    string expr1 = "2+3";
    string expr2 = "2+3*4";
    string expr3 = "(2+3)*4";
    string expr4 = "5+3*8-2";
    string expr5 = "(5+3)*(8-2)";
    string expr6 = "6/2-3+4*5";
    string expr7 = "((2+3)*4-5)/6";
    string expr8 = "2+3-4*5/6";

    cout << "Infix:    " << expr1 << endl;
    cout << "Postfix:  " << infixToPostfix(expr1) << endl
         << endl;

    cout << "Infix:    " << expr2 << endl;
    cout << "Postfix:  " << infixToPostfix(expr2) << endl
         << endl;

    cout << "Infix:    " << expr3 << endl;
    cout << "Postfix:  " << infixToPostfix(expr3) << endl
         << endl;

    cout << "Infix:    " << expr4 << endl;
    cout << "Postfix:  " << infixToPostfix(expr4) << endl
         << endl;

    cout << "Infix:    " << expr5 << endl;
    cout << "Postfix:  " << infixToPostfix(expr5) << endl
         << endl;

    cout << "Infix:    " << expr6 << endl;
    cout << "Postfix:  " << infixToPostfix(expr6) << endl
         << endl;

    cout << "Infix:    " << expr7 << endl;
    cout << "Postfix:  " << infixToPostfix(expr7) << endl
         << endl;

    cout << "Infix:    " << expr8 << endl;
    cout << "Postfix:  " << infixToPostfix(expr8) << endl
         << endl;

    cout << "Done!" << endl;

    return 0;
}