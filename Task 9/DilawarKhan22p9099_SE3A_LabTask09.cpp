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
class Tree
{
public:
    Node *root;
        Tree( )
        {
            root=NULL;
        }
    Node *search(Node *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->data == val)
        {
            return root;
        }
        else
        {
           Node* left= search(root->left, val);
           if(left!=NULL)
           {
            return left;
           }
           else
           {
           Node* right=  search(root->right, val);
           return right;
           }
           
        }
    }
    void SetLeft(Node *root, int val)
    {
        if (root->left == NULL)
        {
            root->left = new Node(val);
        }
        else
        {
            cout << "A value already exists at the left of the given Node" << endl;
            return;
        }
    }
    void SetRight(Node *root, int val)
    {
        if (root->right == NULL)
        {
            root->right = new Node(val);
        }
        else
        {
            cout << "A value already exists at the right of the given Node" << endl;
            return;
        }
    }
    
    void PreOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << "\t";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    void InOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        InOrder(root->left);
        cout << root->data << "\t";
        InOrder(root->right);
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
    int MaxDepth(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        int left = MaxDepth(root->left);
        int right = MaxDepth(root->right);

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
    int Level(Node* root, int val, int level)
    {
        if(root==NULL)
        {
            return 0;
        }
        else if(root->data==val)
        {
            return level;
        }
    
          int left=  Level(root->left,val,level+1);
          int right=  Level(root->right,val,level+1);
        
        if(left!=0)
        {
            return left;
        }
        else
        {
            return right;
        }

    }
    void Delete_Tree(Node* root)
    {
        if(root==NULL)
        {
            return ;
        }
        else
        {
            Delete_Tree(root->left);
            Delete_Tree(root->right);
            delete root;
        }

    }
    bool IsEmpty()
    {
        if (root==NULL)
        {
            return true ;
        }
        else 
        {
            return false;
        }
    }
};
int main()
{
    int x;
    int par;
    int val;
    Node* leaf;
    Tree t1;


    while(1)
    {
        cout<<"PLEASE SELECT AN OPTION "<<endl;
        cout<<"1- Insert in the tree "<<endl;
        cout<<"2- Traverse the tree "<<endl;
        cout<<"3- Find the depth of the tree "<<endl;
        cout<<"4- Find level of specific Node "<<endl;
        cout<<"5- Search a value "<<endl;
        cout<<"6- Delete tree "<<endl;
        cout<<"7- Exit"<<endl;
        cin>>x;


        if(x==1 )
        {
            if(t1.IsEmpty()==true)
            {
                cout<<"Enter the value you want to insert in the tree "<<endl;
                cin>>val;
                t1.root=new Node(val);
            }
            else
            {
            cout<<"Please enter the value of Node at which you want to insert "<<endl;
            cin>>par;
            cout<<"Enter the value you want to insert "<<endl;
            cin>>val;
            cout<<"Select an option "<<endl;
            cout<<"1- Insert at left "<<endl;
            cout<<"2- Insert at right "<<endl;
            cin>>x;

            leaf=t1.search(t1.root,par);
            if(x==1)
            {
                t1.SetLeft(leaf,val);
            }
            else if (x==2)
            {
                t1.SetRight(leaf,val);
            }

            }

        }
        else if(x==2 )
        {
            cout<<"Please select the traversal method "<<endl;
            cout<<"1- Pre-Order Traversal "<<endl;
            cout<<"2- In-Order Traversal "<<endl;
            cout<<"3- Post-Order Traversal "<<endl;
            cin>>x;
            if(x==1)
            {
                if(t1.IsEmpty())
                {
                    cout<<"The tree is empty "<<endl;
                }
                else
                {
                t1.PreOrder(t1.root);
                cout<<endl;
                }
            }
            else if(x==2 )
            {
                if(t1.IsEmpty())
                {
                    cout<<"The tree is empty "<<endl;
                }
                else
                {
                t1.InOrder(t1.root);
                cout<<endl;
                }
            }
            else if(x==3 )
            {
                if(t1.IsEmpty())
                {
                    cout<<"The tree is empty "<<endl;
                }
                else
                {
                t1.PostOrder(t1.root );
                cout<<endl;
                }
            }
        }
        else if (x==3)
        {
            int depth =t1.MaxDepth(t1.root);
            cout<<"The max depth of tree is "<< depth <<endl;
        }
        else if (x==4 )
        {
            cout<<"Enter the value of node to find it's level "<<endl;
            cin>>val;
            int lvl=t1.Level(t1.root,val,0);
            cout<<"Level of the given Node is "<<lvl<<endl;
        }
        else if (x==5)
        {
            cout<<"Enter the value of Node you want to search"<<endl;
            cin>>val;
            leaf=t1.search(t1.root, val);
            if (leaf==NULL)
            {
                cout<<"The value does not exists in the tree"<<endl;

            }
            else
            {
                cout<<"The value "<<leaf->data<<" exists in the tree "<<endl;
            }

        }
        else if(x==6)
        {
            t1.Delete_Tree(t1.root);
            cout<<"Tree Successfully deleted "<<endl;
            t1.root=NULL;
        }
        else if (x==7 )
        {
            cout <<"Program exited successfully "<<endl;
            return 0;
        }

    }
}
