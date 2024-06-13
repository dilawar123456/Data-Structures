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
    void Remove(int pos)
    {
        if(pos<1 || pos>length)
        {
            cout<<"Invalid position "<<endl;
            return ;
        }
        else if(length==0)
        {
            cout<<"List already empty "<<endl;
            return ;
        }
        else if (pos==1)
        {
            Node * curr=head;
            head=head->next;
            head->prev=NULL;
            delete curr;
        }
        else
        {
            Node* curr1=head;
            Node* curr2=head;
            for(int i=1;i<pos;i++)
            {
                curr1=curr2;
                curr2=curr2->next;

            }
            curr1->next=curr2->next;
            if(curr2->next!=NULL)
            {
            curr2->next->prev=curr1;
            }
            delete curr2;

        }
        length--;
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


};
int main()
{
    DoublyList l1;
    l1.Insert(1,1);
    l1.Insert(2,2);
    l1.Insert(3,3);
    l1.Remove(3);
    l1.Print();

}
