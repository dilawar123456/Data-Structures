#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class List
{
    int length;
    Node *head;

public:
    List();
    void Insert(int val, int pos);
    void Print();
    void MinMaxRemove();

};
List::List()
{
    length = 0;
    head = NULL;
}
void List::Insert(int val, int pos)
{
    if (pos < 1 || pos > length + 1)
    {
        cout << "Invalid Position " << endl;
        return;
    }
    else
    {
        Node *n = new Node(val);
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *curr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
}
void List::Print()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "-->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}
void List::MinMaxRemove()
{
    Node* min=new Node(100);
    Node* max=new Node(0);
    Node* minprev=NULL;
    Node* maxprev=NULL;
    Node * curr=head;
    Node* curr2=NULL;
    Node* curr3=NULL;
    while(curr!=NULL)
    {
        if(curr->data<min->data)
        {
            min=curr;
            minprev=curr2;
        }
        
        if(curr->data>max->data)
        {
            max=curr;
            maxprev=curr3;
        }
        curr2=curr;
        curr3=curr;
        curr=curr->next;
       

    }
     if(min==head)
        {
            head=head->next;
            delete min;
            length--;
        }
        else
        {
            minprev->next=min->next;
            delete min;
            length--;
        }
        if(max==head)
        {
            head=head->next;
            delete head;
            length--;
        }
         else
        {
            maxprev->next=max->next;
            delete max;
            length--;
        }


}
int main()
{
    List l1;
    l1.Insert(1,1);
    l1.Insert(2,2);
    l1.Insert(9,3);
    l1.Insert(4,4);
    l1.Insert(5,5);
    l1.Print();
    cout<<"Removed"<<endl;
    l1.MinMaxRemove();
    l1.Print();
}