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
        left = right = nullptr;
    };
};
int kthSmallest(Node *root, int k)
{
    static int prevorder = 0;
    if (!root)
        return -1;
    if (root->left != nullptr)
    {
        int leftans = kthSmallest(root->left, k);
        if (leftans != -1)
            return leftans;
    }
    if (prevorder + 1 == k)
        return root->data;
    prevorder += 1;
    if (root->right != nullptr)
    {
        int rightans = kthSmallest(root->right, k);
        if (rightans != -1)
            return rightans;
    }
    return -1;
}
void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
int kthsmallest(Node *root, int k)
{
    vector<int> arr;
    inorder(root, arr);
    return arr[k - 1];
}
int main()
{
    fastIO();

    return 0;
}