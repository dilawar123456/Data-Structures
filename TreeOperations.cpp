#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
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
    Node *left(Node *root)
    {
        if (root->left == NULL)
        {
            return NULL;
        }
        else
        {
            return root->left;
        }
    }
    Node *right(Node *root)
    {
        if (root->right == NULL)
        {
            return NULL;
        }
        else
        {
            return root->right;
        }
    }
    
    Node *parent(Node *root, Node *p)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p)
        {
            return NULL;
        }
        else if (root->left == p || root->right == p)
        {
            return root;
        }
        Node *temp = parent(root->left, p);
        if (temp != NULL)
        {
            return temp;
        }
        else
        {
            temp = parent(root->right, p);
            return temp;
        }
    }
    Node *sibling(Node *root, Node *sib)
    {
        Node *par = parent(root, sib);
        if (par==NULL)
        {
            return NULL;
        }
       else  if (par->left == sib)
        {
            return par->right;
        }
        else if (par->right == sib)
        {
            return par->left;
        }
    }
    int Level(Node* root,int val,int lvl )
    {
        if(root==NULL )
        {
            return 0;
        }
        else if(root->data==val)
        {
            return lvl;
        }
        else
        {
            return Level(root->left,val,lvl+1) | 
                    Level(root->right,val,lvl+1);

            
        }

    }
    int maxDepth(Node* root )
    {
        if(root==NULL)
        {
            return -1;
        }

        int l=maxDepth(root->left)+1;
        int r=maxDepth(root->right)+1;
        if(l>r)
        {
            return l;
        }
        else 
        {
            return r;
        }
    }
    // counting through external variable
    int countLeaf(Node *root, int &count)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            count++;
        }
        else
        {

            countLeaf(root->left, count);
            countLeaf(root->right, count);

            return count;
        }
    }
    // counting without a counter
    // most recommended
    int COUNTLEAFS(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return COUNTLEAFS(root->left) + COUNTLEAFS(root->right);
        }
    }

    int countNonLeafs(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        else
        {
            return countNonLeafs(root->left) + countNonLeafs(root->right) + 1;
        }
    }
    bool StrictlyBinary(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        else if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        else if (root->left != NULL && root->right == NULL || root->left == NULL && root->right != NULL)
        {
            return false;
        }
        else
        {
            bool left = StrictlyBinary(root->left);
            bool right = StrictlyBinary(root->right);
            if (left == false)
            {
                return false;
            }
            else
            {
                return right;
            }
        }
    }
};
int main()
{
    Tree t1;
    t1.root = new Node(1);
    t1.root->left = new Node(2);
    t1.root->left->left = new Node(3);
    t1.root->left->right = new Node(4);

    t1.root->right = new Node(5);
    t1.root->right->left = new Node(6);
    t1.root->right->right = new Node(7);
    

    Node *temp = t1.right(t1.root->left->left);
    if (temp == NULL)
    {
        cout << "right does not exists " << endl;
    }
    else
    {
        cout << temp->data << endl;
    }
    Node *t = t1.left(t1.root);
    if (t == NULL)
    {
        cout << "left does not exist " << endl;
    }
    else
    {
        cout << t->data << endl;
    }

    Node *temp1 = t1.parent(t1.root, t1.root->left);
    if (temp1 == NULL)
    {
        cout << "Parent does not exists " << endl;
    }
    else
    {
        cout << temp1->data << endl;
    }

    Node *temp2 = t1.sibling(t1.root, t1.root->right);
    if (temp2 == NULL)
    {
        cout << "The Sibling does not exist " << endl;
    }
    else
    {

        cout << temp2->data << endl;
    }
    int count = 0;
    cout << "Counting through counter " << endl;

    cout << "The number of leaf nodes in the tree are " << t1.countLeaf(t1.root, count) << endl;

    cout << "COUNTING WITHOUT A COUNTER " << endl;
    cout << "The number of leaf nodes in the tree are " << t1.COUNTLEAFS(t1.root) << endl;

    cout << "The number of non leafs nodes are " << t1.countNonLeafs(t1.root) << endl;

    if (t1.StrictlyBinary(t1.root))
    {
        cout << "The tree is strictly binary " << endl;
    }
    else
    {
        cout << "The tree is not strictly binary " << endl;
    }
    cout<<"Level"<<endl;
    cout<<t1.Level(t1.root,4,0);

    cout<<"The max depth is "<<endl;
    cout<<t1.maxDepth(t1.root);
}