#include <iostream>
#include <vector> // vector header file
using namespace std;
int main(int argc, char const *argv[])
{
    // declaring a vector
    vector<int> v1;

    // size of the vector
    cout << v1.size() << std::endl;
    // capacity of vector- double rule
    cout<< v1.capacity()<<endl;

    // taking input using pushback method
        v1.push_back(8);
        v1.push_back(7);
        v1.push_back(6);
        v1.push_back(4);
        v1.push_back(3);
        //int element;
        // for (int i = 0; i < 4; i++)
        // {
        //     cin >> element;
        //     v1.push_back(element);
        // }


    // printing vector contents
        for (int i = 0; i < 6; i++)
        {
        // cout << v1[i] << endl;
        cout<<v1.at(i)<<endl;
        }


    // remove values from vector
        v1.pop_back();
        for (auto num : v1)
            cout << num;


    // to remove all values
        // v1.clear();
        // cout << v1.size() << endl;

    // initialize vector
        vector<int> v2(5);
        v2[2] = 5;
        cout << v2[2] << endl;
        vector<int> v3(5, 69);
        // all initialized to 69. xd :))
        for (auto num : v3)
            cout << num << " ";

        cout << endl;

        vector<int> v4{3, 2, 235, 35, 6, 2, 25, 6, 6, 24, 547, 75};
        for (auto x : v4)
            cout << x << " ";
        cout << endl;

    // sum of vectors
        vector<int> v5;
        int input;
        for (int i = 0; i < 5; i++)
        {
            cin >> input;
            v5.push_back(input);
        }
        int sum = 0;
        for (auto num : v5)
            sum += num;

        cout << sum << endl;

    return 0;
}
