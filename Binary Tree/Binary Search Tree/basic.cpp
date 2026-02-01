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

Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *buildBST(vector<int> arr)
{
    Node *root = nullptr;
    for (auto val : arr)
    {
        root = insert(root, val);
    }
    return root;
}

bool search(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}


/*Delete Node in BST
1. no child node
2.one child;
3. two children
*/
Node*getInorderSuccessor(Node*root)
{
    while (root!=nullptr&&root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
    
}

Node *delNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (key < root->data)
    {
        root->left = delNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delNode(root->right, key);
    }
    else
    {

        // key==root
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            // 2 children
            Node *IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }
    return root;
}

int main()
{
    fastIO();
    vector<int> v = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(v);
    cout << search(root, 2) << endl;
    
    return 0;
}