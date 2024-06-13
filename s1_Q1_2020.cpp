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
    void Split(List &l1,List &l2)
    {
        Node* curr=head;
        Node* curr1=l1.head;
        Node* curr2=l2.head;
        int temp;

        if(length%2==0)
        {
            temp=length/2;
        }
        else{
            temp=(length/2)+1;
        }
        for(int i=0;i<temp;i++)
        {
            if(l1.head==NULL)
            {
                
            }
        }
    }
};
int main()
{
    List l1,l2,l3;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Insert(6);
    l1.Insert(7);
    l1.Insert(8);
    l1.Insert(9);
    l1.Insert(10);

    l1.Print();

}