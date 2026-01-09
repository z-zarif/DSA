#include <bits/stdc++.h>
using namespace std;
// last opening bracket= first closing bracket
//  if there is something like last first going on
//  we should use stack DS
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i]);
            }
            else
            {
                if (s1.size() == 0)
                {
                    return false;
                }

                char top = s1.top();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '['))
                {
                    return false;
                }
                s1.pop();
            }
        }
        return s1.size() == 0;
    }
};