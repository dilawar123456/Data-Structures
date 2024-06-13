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
    void reverseKNodes(int k)
    {
        Node *curr1 = head;
        Node *curr2 = head;
        Node *temphead = head;
        int jumps=length/k;
        if(jumps%2!=0)
        {
            jumps=jumps+1;
        }
        jumps=jumps/2;
        int loop = k;
        int temp = 0;
       
     

        for (int i = 1; i <=jumps; i++)
        {
            while (loop > (k / 2))
            {
                for (int j = 1; j < loop; j++)
                {
                    if (curr2->next != NULL) 
                        curr2 = curr2->next;
                }
                temp = curr1->data;
                curr1->data = curr2->data;
                curr2->data = temp;
                loop--;
                curr2=temphead;
                curr1 = curr1->next;
            }
            for (int l = 1; l <= (k*2); l++)
            {
                if (temphead != NULL)
                    temphead = temphead->next;
            }
            if (temphead != NULL)
            {
                curr1 = temphead;

                curr2 = temphead;
            }
            loop = k;
        }
    }
};
int main()
{
    List l1;
    l1.Insert(1, 1);
    l1.Insert(2, 2);
    l1.Insert(3, 3);
    l1.Insert(4, 4);
    l1.Insert(5, 5);
    l1.Insert(6, 6);
    l1.Insert(7, 7);
    l1.Insert(8, 8);
    l1.Insert(9, 9);
    l1.Insert(10, 10);
    l1.Insert(11, 11);
    l1.Insert(12, 12);
    l1.Insert(13, 13);
    l1.Insert(14, 14);
    l1.Insert(15, 15);
    l1.Insert(16,16);

    l1.Print();

    l1.reverseKNodes(4);
    l1.Print();
}