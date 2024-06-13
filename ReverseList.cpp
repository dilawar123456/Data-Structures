#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    Node *prev;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev=NULL;
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
void Insert(int val, int pos)
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
            if(head==NULL)
            {
                head=n;
            }
            else
            {
            n->next = head;
            head->prev=n;
            head = n;
            }
        }
        else
        {
            Node *curr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            n->prev=curr;
            if(curr->next!=NULL)
            {
            curr->next->prev=n;
            }
            curr->next = n;
        }
        length++;
    }
}
void Print()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "<==>";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}
void Remove(int pos)
{
    if (pos < 1 || pos > length)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (length==0)
    {
        cout<<"List already empty "<<endl;
        return ;
    }
    else
    {
        Node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            head->prev=NULL;
            delete curr;
        }
        else
        {
            Node *curr2 = head;
            for (int i = 1; i < pos; i++)
            {
                curr = curr2;
                curr2 = curr2->next;
            }
            curr->next = curr2->next;
            curr2->next->prev=curr;
            delete curr2;
        }
        length--;
    }
}
void Reverselist()
{
    Node* curr=head;
    Node* temp=NULL;
    Node* curr2=NULL;

        while(curr!=NULL)
        {
        temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;
        curr2=curr;
        curr=curr->prev;
        }
    

    head=curr2;
    

    
    

}

};
int main()
{
    List l1;
    l1.Insert(2,1);
    l1.Insert(4,2);
    l1.Insert(6,3);
    l1.Insert(8,4);
    l1.Insert(10,5);
    l1.Insert(12,6);
    l1.Insert(14,7);
    l1.Print();
    l1.Reverselist();
    cout<<"list reversed"<<endl;
    l1.Print();
}