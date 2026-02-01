#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
class node
{
public:
    int data;
    node *left;
    node *right;
};
int totalNodes(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = totalNodes(root->left);
    int right = totalNodes(root->right);
    return left + right + 1;
}
// with the given data
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// Driver Code
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);
    cout << totalNodes(root);
    return 0;
}