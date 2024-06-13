#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        height=1;
        left=NULL;
        right=NULL;
    }
};
class AVL_Tree
{
    public:
    Node* root;
    AVL_Tree()
    {
        root=NULL;
    }
    int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else 
        {
            return root->height;
        }
    }
    int Max(int a , int b)
    {
        if (a>b)
        {
            return a;
        }
        else 
        {
            return b;
        }
    }
    Node* RotateLeft(Node* root)
    {
        Node* y=root->right;
        Node* temp=y->left;
        y->left=root;
        root->right=temp;

        root->height=1+Max(height(root->left),height(root->right));
        y->height=1+Max(height(y->left),height(y->right));
        return y;

    }
     Node* RotateRight(Node* root)
    {
        Node* y=root->left;
        Node* temp=y->right;
        y->right=root;
        root->left=temp;

        root->height=1+Max(height(root->left),height(root->right));
        y->height=1+Max(height(y->left),height(y->right));
        return y;

    }
    
    int get_balance(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
        return height(root->left)-height(root->right);
        }
    }
    Node *Insert(Node* root, int val )
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

        root->height=1+ Max(height(root->left),height(root->right));

        int balance=get_balance(root);

        if(balance>1 && val<root->left->data)
        {
            return RotateRight(root);
        }
        else if(balance>1 && val>root->left->data)
        {
           root->left= RotateLeft(root->left);
           return RotateRight(root);

        }
        else if(balance<-1 && val>root->right->data)
        {
           return RotateLeft(root);
        } 
        else if(balance<-1 && val<root->right->data)
        {
            root->right=RotateRight(root->right);
            return RotateLeft(root);
        }

        return root;

    }
    
	Node* Successor(Node * root)
	{
		if (root==NULL )
		{
			return NULL;
		}
		else if (root->left==NULL)
		{
			return root;
		}
		else
		{
			return Successor(root->left);
		}
	}

   Node* Delete(Node* root,int val)
    {
      if(root==NULL )
		{
			return NULL;
		}
		else if (val>root->data)
		{
			root->right=Delete(root->right,val);
		}
		else if(val<root->data)
		{
			root->left=Delete(root->left,val);
		}
		else 
		{
			if (root->right==NULL && root->left==NULL)
			{
				delete root;
				root=NULL;
			}
			else if( root->left==NULL)
			{
				Node *temp=root;
				root=root->right;
				delete temp;
				temp=NULL;
				return root; 
			}
			else if (root->right==NULL)
			{
				Node* temp=root;
				root=root->left;
				delete temp;
				temp=NULL;
				return root;
			}
			else 
			{
				Node* temp =Successor(root->right);
				root->data=temp->data;
				root->right= Delete(root->right,temp->data);
				
			}
		}
       
        int balance=get_balance(root);

        if(balance>1 && val<root->left->data)
        {
            return RotateRight(root);
        }
        else if(balance>1 && val>root->left->data)
        {
           root->left= RotateLeft(root->left);
           return RotateRight(root);

        }
        else if(balance<-1 && val>root->right->data)
        {
           return RotateLeft(root);
        } 
        else if(balance<-1 && val<root->right->data)
        {
            root->right=RotateRight(root->right);
            return RotateLeft(root);
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
    void Update(int val2,int val )
    {
        Delete(root,val);
        Insert(root,val2);
        
    }
    Node* Findmax(Node* root)
    {
        if(root==NULL )
        {
            return NULL;
        }
        else if( root->right==NULL)
        {
            return root;
        }
        else 
        {
            return Findmax(root->right);
        }
    }
    Node* FindMin(Node* root)
    {
        if(root==NULL )
        {
            return NULL;
        }
        else if( root->left==NULL)
        {
            return root;
        }
        else 
        {
            return Findmax(root->left);
        }
    }

};
int main()
{
    int x;
    int val,val2;
    AVL_Tree a1;

    while(1)
    {
        cout<<"PLEASE SELECT AN OPTION "<<endl;
        cout<<"1- Insert a value "<<endl;
        cout<<"2- Delete a value "<<endl;
        cout<<"3- Display tree"<<endl;
        cout<<"4- Update a value "<<endl;
        cout<<"5- Search a value "<<endl;
        cout<<"6- Find Max "<<endl;
        cout<<"7- Find Min"<<endl;
        cout<<"8- Exit "<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter the value to Insert "<<endl;
            cin>>val;
           a1.root= a1.Insert(a1.root,val);
        }
        else if(x==2)
        {
            cout<<"Enter the value of Node you want to delete "<<endl;
            cin>>val;
            a1.Delete(a1.root,val);
        }
        else if (x==3)
        {
            cout<<"PreOrder Traversal :-"<<endl;
            a1.PreOrder(a1.root);
            cout<<endl;
        }
        else if(x==4)
        {
            cout<<"Enter the value of Node you want to update "<<endl;
            cin>>val;

            Node *temp=a1.Search(a1.root,val);
            if(temp==NULL)
            {
                cout<<"The Node does not exist "<<endl;
            }
            else 
            {
                cout<<"Enter the updated value "<<endl;
                cin>>val2;
                a1.Update(val2,val);
                cout<<"Value Updated "<<endl;
            }
        }
        else if (x==5)
        {
            cout<<"Enter the value you want to search in the tree "<<endl;
            cin>>val;
            Node* temp= a1.Search(a1.root,val );
            if(temp==NULL)
            {
                cout<<" The Node does not exist "<<endl;
            }
            else 
            {
                cout<<temp->data<<" found in the AVL tree "<<endl;
            }

        }
        else if( x==6 )
        {
            Node* temp=a1.Findmax(a1.root);
            if(temp==NULL)
            {
                cout<<"The tree is empty "<<endl;
            }
            else 
            {
                cout<<"The maximum value in the tree is "<<temp->data<<endl;
            }
        }
        else if (x==7)
        {
             Node* temp=a1.FindMin(a1.root);
            if(temp==NULL)
            {
                cout<<"The tree is empty "<<endl;
            }
            else 
            {
                cout<<"The minimum value in the tree is "<<temp->data<<endl;
            }
        }
        else if (x==8)
        {
            cout<<"Program exited successfully "<<endl;
            return 0;
        }

    }
}