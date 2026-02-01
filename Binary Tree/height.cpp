#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int getHeightTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = getHeightTree(root->left);
    int right = getHeightTree(root->right);
    return max(left, right) +1;
    //return max(left, right) + 1;
}

int main()
{
    fastIO();

    // Representation of the input tree:
    //     12
    //    /  \
    //   8   18
    //  / \
    // 5   11
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);
    cout<<getHeightTree(root);

    return 0;
}