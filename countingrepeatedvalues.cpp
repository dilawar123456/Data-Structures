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
    int count();
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
int List::count()
{
    Node* curr=head;
    Node* curr1=head->next;
    int *arr=new int[length];
    int k=0;
    int count=0;
    int check=0;

    while(curr->next!=NULL)
    {
        check=0;
            curr1=curr->next;
        while(curr1!=NULL)
        {
            
            if(curr->data==curr1->data)
            {
                for(int i=0;i<k;i++)
                {
                    if(arr[i]==curr->data)
                    {
                        check=1;
                    }
                }
                if(check==0)
                {
                arr[k]=curr->data;
                count++;
                k++;
                break;
                }
                
                
                
            }
          curr1=curr1->next;
           
        }
         curr=curr->next;
         
         
    }
    return count;
}
int main()
{
    List l1;
    l1.Insert(1,1);
    l1.Insert(2,2);
    l1.Insert(3,3);
    l1.Insert(3,4);
    l1.Insert(2,5);
    l1.Insert(3,6);
    l1.Insert(3,7);
    l1.Insert(4,8);
    l1.Insert(4,9);
    l1.Insert(1,10);
    l1.Insert(1,11);
    cout<<"_-----------"<<endl;
    cout<<l1.count();

    
}