// push, pop from front and back
// value from front and back
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(3);
    dq.push_back(5);
    dq.push_front(7);
    while (!dq.empty())
    {
        cout << dq.front() << endl;
        dq.pop_front();
    }

    return 0;
}
