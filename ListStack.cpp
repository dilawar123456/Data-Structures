#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data )
    {
        this->data=data;
        next=NULL;
    }

};
class Stack
{
    Node* head;
    int length;
    public:
    Stack()
    {
        head=NULL;
        length=0;
    }
    void Push(int val)
    {
        Node* n=new Node(val);
        n->next=head;
        head=n;
        length++;
    }
    int Pop()
    {
        if(length==0)
        {
            cout<<"Stack underflow "<<endl;
            return -1;
        }
       
       else 
       { int temp=head->data;
        Node* curr=head;
        head=head->next;
        delete curr;
        length--;
        return temp;
       }
    }
    int Top()
    {
        return head->data;
    }

};
int main ()
{
    int x;
    int val;
    Stack s1;

    while(1)
    {
        cout<<"Please select an option "<<endl;
        cout<<"1- Push"<<endl;
        cout<<"2- Pop"<<endl;
        cout<<"3- Get"<<endl;
        cout<<"4- Exit"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter value "<<endl;
            cin>>val;
            s1.Push(val);

        }
        else if (x==2)
        {
            cout<<"value popped "<<s1.Pop()<<endl;
        }
        else if(x==3)
        {
            cout<<"value :"<<s1.Top()<<endl;
        }
        else if (x==4)
        {
            cout<<"program exited successfully "<<endl;
            return 0;
        }
    }
}