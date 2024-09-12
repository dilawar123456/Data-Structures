#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
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
    bool Isempty()
    {
        if(root==NULL)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    Node* Search(Node* root, int val )
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if( root->data==val)
        {
            return root;
        }
        else if(val<root->data)
        {
            return Search(root->left,val);
        }
        else if(val>root->data)
        {
            return Search(root->right,val);
        }
        
    }
    Node* Insert(Node* root,int val)
    {
        if(root==NULL )
        {
            return new Node(val);
        }
        else if (root->data==val)
        {
            cout<<"Can't Insert same value twice "<<endl;
            return root;
        }
        else if(val>root->data)
        {
            root->right=Insert(root->right,val);

        }
        else if(val<root->data)
        {
            root->left=Insert(root->left,val);
        }
        return root;

    }
    Node* Successor(Node* root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->left==NULL)
        {
            return root;
        }
        else 
        {
            return Successor(root->left);
        }
    }
    Node* Delete(Node* root,int val )
    {
        if(root==NULL )
        {
            return NULL;
        }
        else if(val>root->data)
        {
           root->right= Delete(root->right,val);
        }
        else if (val<root->data)
        {
            root->left= Delete(root->left,val);
        }
        else 
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                root=NULL;
            }
            else if(root->left==NULL)
            {
                 Node* temp=root;
                 root=root->right;
                 delete temp;
                 temp=NULL;
            }
            else if(root->right==NULL)
            {
                Node* temp=root;
                root=root->left;
                delete temp;
                temp=NULL;
            }
            else if(root->left!=NULL && root->right!=NULL)
            {
                Node* temp=Successor(root->right);
                root->data=temp->data;

               root->right= Delete(root->right,temp->data);
            }
        }

        return root;
    }
    void PreOrder(Node* root )
    {
        if(root==NULL)
        {
            return;
        }
        else 
        {
            cout<<root->data<<"\t";
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    void InOrder(Node* root )
    {
        if(root==NULL)
        {
            return;
        }
        else 
        {
            
            InOrder(root->left);
            cout<<root->data<<"\t";
            InOrder(root->right);
        }
    }
    void PostOrder(Node* root )
    {
        if(root==NULL)
        {
            return;
        }
        else 
        {
            
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<root->data<<"\t";
        }
    }
    

};
int main()
{
    BST b1;

  b1.root=  b1.Insert(b1.root,10);
  b1.root=  b1.Insert(b1.root,8);
  b1.root=  b1.Insert(b1.root,12);
  b1.root=  b1.Insert(b1.root,5);
  b1.root=  b1.Insert(b1.root,9);
  b1.root=  b1.Insert(b1.root,11);
  b1.root=  b1.Insert(b1.root,13);

    cout<<"Searching for Nodes "<<endl;
    Node* temp=b1.Search(b1.root,11);
    if(temp==NULL)
    {
        cout<<"Node does not exist in tree "<<endl;
    }
    else
    {
        cout<<temp->data<<" found in the BST "<<endl;
    }
    cout<<"Pre-Order Traversal Before Deletion "<<endl;
    b1.PreOrder(b1.root);
    cout<<endl;

    b1.root=  b1.Delete(b1.root,5);
    cout<<"Pre-Order Traversal After Deleting Leaf-Node"<<endl;
    b1.PreOrder(b1.root);
    cout<<endl;
    
    b1.root=b1.Delete(b1.root,8);
    cout<<"Pre-Order Traversal After Deleting Node with one child "<<endl;
    b1.PreOrder(b1.root);
    cout<<endl;

    b1.root=b1.Delete(b1.root,12);
    cout<<"Pre-Order Traversal after Deleting Node with two child "<<endl;
    b1.PreOrder(b1.root);
    cout<<endl;

}