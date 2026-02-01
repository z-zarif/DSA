// for validating a BST,
//  left max< node.val< right min
#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
/**
 * Definition for a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool helper(TreeNode *root, TreeNode *max, TreeNode *min)
{
    if (!root)
    {
        return true;
    }
    if (root && root->val <= min->val)
    {
        return false;
    }
    if (root && root->val >= max->val)
    {
        return false;
    }
    return helper(root->left, root, min) && helper(root->right, max, root);
}
bool isValidBST(TreeNode *root)
{
    return helper(root, nullptr, nullptr);
}

int main()
{
    fastIO();

    return 0;
}