#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int height(Node *n)
    {
        if (n == nullptr)
            return 0;

        return n->height;
    }

    int getBalance(Node *n)
    {
        if (n == nullptr)
            return 0;

        return height(n->left) - height(n->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *z = x->right;

        x->right = y;
        y->left = z;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *z = y->left;

        y->left = x;
        x->right = z;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node *insertNode(Node *node, int key, bool &inserted)
    {
        if (node == nullptr)
        {
            inserted = true;
            return new Node(key);
        }

        if (key < node->key)
        {
            node->left = insertNode(node->left, key, inserted);
        }
        else if (key > node->key)
        {
            node->right = insertNode(node->right, key, inserted);
        }
        else
        {
            inserted = false;
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // LL
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // RR
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // LR
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *inorderSuccessor(Node *node)
    {
        Node *current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    Node *deleteNode(Node *node, int key)
    {
        if (node == nullptr)
            return nullptr;

        
        if (key < node->key)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Only right child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            // Only left child
            if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Two children
            Node *temp = inorderSuccessor(node->right);

            node->key = temp->key;

            node->right = deleteNode(node->right, temp->key);
        }

        // Update height
        node->height = 1 + max(height(node->left),
                               height(node->right));

        int balance = getBalance(node);

        // LL
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        // LR
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        // RL
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node *node, vector<int> &result)
    {
        if (node == nullptr)
            return;

        inorder(node->left, result);
        result.push_back(node->key);
        inorder(node->right, result);
    }

    bool findNode(Node *node, int key)
    {
        if (node == nullptr)
            return false;

        if (node->key == key)
            return true;

        if (key < node->key)
            return findNode(node->left, key);
        else
            return findNode(node->right, key);
    }

    string treeString(Node *node)
    {
        if (node == nullptr)
            return "";

        if (node->left == nullptr && node->right == nullptr)
            return to_string(node->key);

        return to_string(node->key) + "(" +
               treeString(node->left) + " ," +
               treeString(node->right) + ")";
    }

    void clear(Node *node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);

        delete node;
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    ~AVLTree()
    {
        clear(root);
    }

    bool insert(int key)
    {
        bool inserted = false;

        root = insertNode(root, key, inserted);

        return inserted;
    }

    bool erase(int key)
    {
        if (!find(key))
            return false;

        root = deleteNode(root, key);

        return true;
    }

    bool find(int key)
    {
        return findNode(root, key);
    }

    vector<int> traverse()
    {
        vector<int> result;

        inorder(root, result);

        return result;
    }

    string toString()
    {
        return treeString(root);
    }
};

int main()
{
    AVLTree tree;

    ifstream inputFile("testcase_avl.txt");
    ofstream outputFile("output avl.txt");

    if (!inputFile)
    {
        cout << "Could not open testcase_avl.txt\n";
        return 1;
    }

    if (!outputFile)
    {
        cout << "Could not create output avl.txt\n";
        return 1;
    }

    char command;
    int x;

    while (inputFile >> command)
    {
        if (command == 'I')
        {
            inputFile >> x;

            if (tree.insert(x))
                outputFile << tree.toString() << '\n';
            else
                outputFile << "duplicate\n";
        }

        else if (command == 'D')
        {
            inputFile >> x;

            if (tree.erase(x))
                outputFile << tree.toString() << '\n';
            else
                outputFile << "not found\n";
        }

        else if (command == 'F')
        {
            inputFile >> x;

            if (tree.find(x))
                outputFile << "found\n";
            else
                outputFile << "not found\n";
        }

        else if (command == 'T')
        {
            vector<int> v = tree.traverse();

            for (int i = 0; i < (int)v.size(); i++)
            {
                if (i > 0)
                    outputFile << " ";

                outputFile << v[i];
            }

            outputFile << '\n';
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}