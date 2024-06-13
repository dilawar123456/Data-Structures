#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    Node *Insert(Node *root, int val)
    {
        if (root == NULL)
        {
            return new Node(val);
        }
        else if (root->data == val)
        {
            cout << "Gem already Present " << endl;
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
        return root;
    }
     void InOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {

            InOrder(root->left);
            cout << root->data << "\t";
            InOrder(root->right);
        }
    }
    int closest_Distance(Node* root )
    {
        if(root==NULL )
        {
            return -1;

        }
        else if(root->left==NULL && root->right==NULL)
        {
            return 0;
        }
        else
        {
            int l=closest_Distance(root->left)+1;
            int r=closest_Distance(root->right)+1;
            if(l<r && l>0)
            {
                return l;

            }
            else 
            {
                return r;
            }
        }
    }
    Node* fun(Node* root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return root;
        }
        else if (root->left!=NULL)
        {
            
        }
        
    }
};
int main()
{
    BST b1;
  b1.root=  b1.Insert(b1.root,12);
  b1.root=  b1.Insert(b1.root,8);
   b1.root= b1.Insert(b1.root,7);
    b1.root=b1.Insert(b1.root,13);
    b1.root=b1.Insert(b1.root,14);
    b1.root=b1.Insert(b1.root,15);
    b1.root=b1.Insert(b1.root,17);

    cout<<b1.closest_Distance(b1.root);
}