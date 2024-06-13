#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
Node* root;
BST()
{
    root=NULL;
}
void Insert(Node* &root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
    }
    else if(root->data==val)
    {
        cout<<"can't Insert same value twice"<<endl;
        return;
    }
    else if(val> root->data)
    {
        if(root->right!=NULL)
        {
            Insert(root->right,val);

        }
        else if (root->right==NULL)
        {
            root->right=new Node(val);
        }
    }
    else if (val< root->data)
    {
        if(root->left!=NULL)
        {
            Insert(root->left,val);

        }
        else if (root->left==NULL)
        {
            root->left=new Node(val);
        }
    }

}
void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inOrder(root->left);
        cout << root->data << "\t";
        inOrder(root->right);
        
    }
};
int main()
{
    BST b1;
    b1.Insert(b1.root,1);
    b1.Insert(b1.root,2);
    b1.Insert(b1.root,3);
    b1.Insert(b1.root,4);
    b1.Insert(b1.root,5);
    b1.Insert(b1.root,6);
    b1.Insert(b1.root,7);
    b1.Insert(b1.root,16);
    b1.Insert(b1.root,15);

    b1.inOrder(b1.root);

}