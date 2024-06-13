#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};
class AVL
{
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }
    int height(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            return root->height;
        }
    }
    int Max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int getBalance(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return height(root->left) - height(root->right);
        }
    }
    Node *RotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + Max(height(x->left), height(x->right));
        y->height = 1 + Max(height(y->left), height(y->right));

        return y;
    }
    Node *RotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        x->height = 1 + Max(height(x->left), height(x->right));
        y->height = 1 + Max(height(y->left), height(y->right));

        return x;
    }
   Node *Insert(Node* &root, int val)
{
    if (root == NULL)
    {
        return (new Node(val));
    }
    else if (root->data == val)
    {
        cout << "Can't Insert the same value Twice" << endl;
        return root;
    }
    else if (val > root->data)
    {
        root->right = Insert(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = Insert(root->left, val);
    }

    root->height = 1 + Max(height(root->left), height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && val < root->left->data)
    {
        return RotateRight(root);
    }
    else if (balance > 1 && val > root->left->data)
    {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    else if (balance < -1 && val > root->right->data)
    {
        return RotateLeft(root);
    }
    else if (balance < -1 && val < root->right->data)
    {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    // If no rotation is required, return the current root node
    return root;
}

    void Inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        Inorder(root->left);
        cout << root->data << "\t";
        Inorder(root->right);
    }
    void PostOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << "\t";
    }
};

    int main()
{
    AVL a1;

    a1.root = a1.Insert(a1.root, 1);
    a1.root = a1.Insert(a1.root, 2);
    a1.root = a1.Insert(a1.root, 3);
    a1.root = a1.Insert(a1.root, 4);
    a1.root = a1.Insert(a1.root, 5);
    a1.root = a1.Insert(a1.root, 6);
    a1.root = a1.Insert(a1.root, 7);
    a1.root = a1.Insert(a1.root, 16);
    a1.root = a1.Insert(a1.root, 15);

    a1.PostOrder(a1.root);
}

