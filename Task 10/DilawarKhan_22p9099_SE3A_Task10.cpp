#include <iostream>
using namespace std;
class Node
{
    public:
    string gem;
    int power;
    Node* left;
    Node* right;
    Node(string gem,int power)
    {
        this->gem=gem;
        this->power=power;
        left=NULL;
        right=NULL;
    }
};
class BST
{
    public:
    Node* root ;
    BST()
    {
        root=NULL;
    }
    Node* Insert(Node* root,string gem, int power)
    {
        if(root==NULL)
        {
            return new Node(gem,power);
        }
        else if(root->power==power)
        {
            cout<<"Gem already Present "<<endl;
            return root;
        }
        else if(power>root->power)
        {
             root->right= Insert(root->right,gem,power);
        }
        else if(power<root->power)
        {
            root->left= Insert(root->left,gem,power);
        }
        return root;

    }
    Node* Search(Node* root,int pow)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->power==pow)
        {
            return root;
        }
        else if (pow>root->power)
        {
            return Search(root->right,pow);
        }
        else if(pow<root->power)
        {
            return Search(root->left,pow);
        }

    }
    Node* MaxPower(Node* root )
    {
        if(root==NULL )
        {
            return NULL;
        }
        else if (root->right==NULL)
        {
            return root;
        }
        else 
        {
            return MaxPower(root->right);
        }
    }
    void PreOrder(Node* root )
    {
        if(root==NULL)
        {
            return ;
        }
        else 
        {
            cout<<"["<<root->gem<<", "<<root->power<<"]\t";
            PreOrder(root->left);
            PreOrder(root->right);

        }
    }
     void InOrder(Node* root )
    {
        if(root==NULL)
        {
            return ;
        }
        else 
        {
            
            InOrder(root->left);
            cout<<"["<<root->gem<<", "<<root->power<<"]\t";
            InOrder(root->right);

        }
    }
     void PostOrder(Node* root )
    {
        if(root==NULL)
        {
            return ;
        }
        else 
        {
            
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<"["<<root->gem<<", "<<root->power<<"]\t";

        }
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
        else if(val>root->power)
        {
           root->right= Delete(root->right,val);
        }
        else if (val<root->power)
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
                root->power=temp->power;

               root->right= Delete(root->right,temp->power);
            }
        }

        return root;
    }
};
int main()
{
    BST b1;
    int bag=0;
    int x;
    int pow;
    int capacity;

    b1.root = b1.Insert(b1.root,"Diamond ",50 );
    b1.root = b1.Insert(b1.root,"Ruby ",30 );
    b1.root = b1.Insert(b1.root,"Sapphire ",70 );
    b1.root = b1.Insert(b1.root,"Pearl ",40 );
    b1.root = b1.Insert(b1.root,"Opal ",10 );
    b1.root = b1.Insert(b1.root,"Garnet ",60 );
    b1.root = b1.Insert(b1.root,"Zircon ",20 );
    b1.root = b1.Insert(b1.root,"Jade ",5 );
   
   cout<<"Welcome to the Magical Forest "<<endl;
   cout<<"How much power can your bag hold "<<endl;
   cin>>capacity;
    
     while(1)
    {
        cout<<"Select an option "<<endl;
        cout<<"1- Display the magical tree"<<endl;
        cout<<"2- Search for a gem by specifying it's power "<<endl;
        cout<<"3- Find the gem with heighest magical power "<<endl;
        cout<<"4- Pluck a gem from the tree "<<endl;
        cout<<"5- Exit "<<endl;
        cin>>x;
        if(x==1 )
        {
            cout<<"Which traversal do you want "<<endl;
            cout<<"1- Pre-Order Traversal "<<endl;
            cout<<"2- In-Order Traversal "<<endl;
            cout <<"3- Post-Order Traversal "<<endl;
            cin>>x;
            if(x==1 )
            {
                b1.PreOrder(b1.root);
                cout<<endl;

            }
            else if(x==2 )
            {
                b1.InOrder(b1.root);
                cout<<endl;
            }
            else if (x==3)
            {
                b1.PostOrder(b1.root);
                cout<<endl;
            }
        }
        else if(x==2)
        {
            cout<<"Enter the power of gem you are searching for "<<endl;
            cin>>pow;
            Node* temp=b1.Search(b1.root,pow);
            if(temp==NULL)
            {
                cout<<"Gem not found in the magical tree "<<endl;
            }
            else 
            {
                cout<<"["<<temp->gem<<", "<<temp->power<<"]"<<" was found in the magical tree "<<endl;

            }

        }
        else if (x==3 )
        {
            cout<<"The gem with heighest magical power is ";
            Node* temp=b1.MaxPower(b1.root);
            cout<<"["<<temp->gem<<", "<<temp->power<<"]"<<endl;

        }
        else if(x==4 )
        {
            cout<<" Magical Tree [Inorder ] : ";
            b1.InOrder(b1.root );
            cout<<endl;
            cout<<"Which gem to pluck ,  Enter power"<<endl;
            cin>>pow;
            Node* temp=b1.Search(b1.root,pow);
            if(temp==NULL )
            {
                cout<<"Gem with such power is not available in the tree "<<endl;
            }
            else 
            {
                cout<<"You Plucked :"<<"["<<temp->gem<<", "<<temp->power<<"]"<<endl;
                bag=bag+temp->power;
                b1.Delete(b1.root,temp->power);
                cout<<"Power in bag "<<bag<<endl;
            }
            if(bag==capacity)
            {
                cout<<"YOU WON!!!  , Now take your bag and run from the forest "<<endl;
                return 0;
            }
            else if(bag>capacity)
            {
            cout<<"YOU LOSE :( ,Your bag bursted "<<endl;
            return 0;

             }

        }
        else if(x==5)
        {
            cout<<"Program Exited Successfully "<<endl;
            return 0;
        }




    }

}