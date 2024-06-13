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
    List()
    {
        length = 0;
        head = NULL;
    }
    void Insert(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n;
        }
        length++;
    }
    void Print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << "-->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
  
    void Sorted_Insert(int val)
    {
        Node* n=new Node(val);
        if(head->data>head->next->data)//descending 
        {
            Node* curr1=head;
            Node *curr2=head;
            if (val>head->data)
            {
                n->next=head;
                head=n;
            }
            
           else
           { 
            
            while(val<curr2->data)
            {
                curr1=curr2;
                curr2=curr2->next;
                if(curr2==NULL)
                {
                    break;
                }
            }
            curr1->next=n;
            
            n->next=curr2;
            
            }
            length++;
            
        }
       else if(head->data<head->next->data)//ascending 
        {
            Node* curr1=head;
            Node *curr2=head;
            if (val<head->data)
            {
                n->next=head;
                head=n;
            }
            else
            {
            while(val>curr2->data)
            {
                curr1=curr2;
                curr2=curr2->next;
                if(curr2==NULL)
                {
                    break;
                }
            }
            curr1->next=n;
            n->next=curr2;}
            length++;
            
        }
    }
};
int main()
{
    List l1;
    l1.Insert(2);
    l1.Insert(4);
    l1.Insert(6);
    l1.Insert(8);
    l1.Insert(10);
    l1.Print();

    cout<<"Sorted Insert "<<endl;
    l1.Sorted_Insert(10000);
    l1.Print();
}