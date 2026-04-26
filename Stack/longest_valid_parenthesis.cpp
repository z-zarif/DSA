#include <bits/stdc++.h>
using namespace std;
int maxLength(string s)
{
    stack<int> s1;
    s1.push(-1);
    int maxlen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            s1.push(i);
        }
        else
        {
            s1.pop();
            if (s1.empty())
            {
                s1.push(i);
            }
            else
            {
                maxlen = max(maxlen, i - s1.top());
            }
        }
    }
    return maxlen;
}
int main()
{
    string s = "(()())";
    cout << maxLength(s) << endl;
    return 0;
}