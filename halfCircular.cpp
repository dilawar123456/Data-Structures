#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class CircularList
{
    int length;
    Node *head;

public:
    CircularList()
    {
        length=0;
        head=NULL;
    }
    void Insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        Node *curr = head;
        Node *n = new Node(val);
        if (pos == 1)
        {

            if (head == NULL)
            {
                head = n;
                head->next = head;
            }
            else
            {
                while (curr->next != head)
                {
                    curr = curr->next;
                }
                n->next = head;
                head = n;
                curr->next = head;
            }
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
    void Print()
    {
        if (head == NULL)
        {
            cout << "The list is empty " << endl;
            return;
        }

        Node *curr = head;
        cout << curr->data << "-->";
        curr = curr->next;
        while (curr != head)
        {
            cout << curr->data << "-->";
            curr = curr->next;
        }
        cout<<endl;
    }
    //Exam Qs Begins from here
    bool search(int val)
    {
        Node* curr=head;
       do
        {
            if (curr->data==val)
            {
                return true;
            }
        } while(curr!=head);

        return false;
    }

    bool Searched(int val)
    {
        if(search(val))
        {
        Node* slow =head;
        Node* fast= head;
        do
        {
            
            fast=fast->next->next;
            slow=slow->next;
            if(fast->next==head)
            {
                break;
            }
        }while(fast!=head);
        fast=head;
        while(fast!=slow)
        {
            if(fast->data==val)
            {
                return true;
            }
            fast=fast->next;
        }

        return false;
        }
        else 
        {
            cout<<"Value does not exist in the list"<<endl;
            return false;
        }
    }

};
int main()
{
    CircularList l1;
    l1.Insert(1,1);
    l1.Insert(2,2);
    l1.Insert(3,3);
    l1.Insert(4,4);
    l1.Insert(5,5);
    l1.Insert(6,6);
    l1.Insert(7,7);
    l1.Insert(8,8);
    l1.Insert(9,9);
   
    l1.Print();
    if(l1.Searched(0))
    {
        cout<<"The value exists in the first half"<<endl;
    }
    else
    {
        cout<<"The value exists in second half "<<endl;
    }

}