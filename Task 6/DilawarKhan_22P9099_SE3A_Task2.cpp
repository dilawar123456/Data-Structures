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
    bool isPalindrome()
    {
        Node* curr1=head;
        Node* curr2=head;
        int temp=length;
        int half=temp/2;
        for(int i=1;i<half;i++)
        {
            curr2=head;

            for(int j=1;j<temp;j++)
            {
                curr2=curr2->next;


            }
            if(curr1->data!=curr2->data)
            {
                return false;
            }
            temp--;
            curr1=curr1->next;

        }
    }

};
int main()
{
    CircularList l1;
    l1.Insert(1,1);
    l1.Insert(2,2);
    l1.Insert(3,3);
    l1.Insert(3,4);
    l1.Insert(2,5);
    l1.Insert(1,6);

    if(l1.isPalindrome())
    {
        cout<<"The list is palindrome "<<endl;

    }
    else{
        cout<<"The list is not palindrome "<<endl;
    }

}