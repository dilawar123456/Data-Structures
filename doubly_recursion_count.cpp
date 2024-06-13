#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }

};
class DoublyList
{
    Node* head;
    int length;
    public:
    DoublyList()
    {
        head=NULL;
        length=0;
        
    }
    void Insert(int val ,int pos )
    {
        if(pos<1 || pos>length+1)
        {
            cout<<"Invalid Position "<<endl;
            return ;
        }
        Node *n=new Node (val);
         if (pos==1)
        {
            if (head!=NULL)
            {
                n->next=head;
                head->prev=n;
            }
            head=n;
        }
        else
        {
            Node *curr=head;
            for(int i=1;i<pos-1;i++)
            {
                curr=curr->next;
            }
            n->next=curr->next;
            n->prev=curr;
            if(curr->next!=NULL)
            {
            curr->next->prev=n;
            }
            curr->next=n;
        }
        length++;
    }
     void Print()
    {
        Node *curr=head;
        for (int i = 0; i < length; i++)
        {
            cout << curr->data<< "-->";
            curr=curr->next;
        }
        cout << endl;
    }
    Node* getHead()
    {
        return head;
    }
    int count(Node *curr)
    {

        if(curr==NULL)
        {
            return 0;
        }
        else
        {
            return count(curr->next)+1;
        }
    }


};
int main()
{
    DoublyList l1;
    l1.Insert(2,1);
    l1.Insert(4,2);
    l1.Insert(6,3);
    l1.Insert(8,4);
    l1.Insert(10,5);
    Node* curr=l1.getHead();
   cout<< l1.count(curr);


}