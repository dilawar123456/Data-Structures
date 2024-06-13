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
    bool LOOP()
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast && fast!=head)
            {
                return true;
            }
            else if(slow==fast && fast==head)
            {
                return false;
            }


        }
        
            return false;
        
    }

};