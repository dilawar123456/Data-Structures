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
    void Remove(int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        if (length == 0)
        {
            cout << "List already Empty " << endl;
            return;
        }

        Node *curr1 = head;
        Node *curr2 = head;
        if (pos == 1)
        {
            while (curr1->next != head)
            {
                curr1 = curr1->next;
            }
            head = head->next;
            curr1->next = head;
            if (head->next == head)
            {
                head = NULL;
            }
            delete curr2;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                curr1 = curr2;
                curr2 = curr2->next;
            }
            curr1->next = curr2->next;
            delete curr2;
        }
        length--;
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
};
int main()
{
    CircularList l1;
    l1.Insert(2,1);
    l1.Insert(4,1);
    l1.Insert(6,1);
    l1.Insert(8,2);
    l1.Insert(10,5);
    l1.Remove(1);
    l1.Remove(4);
    l1.Remove(2);
    l1.Print();
}