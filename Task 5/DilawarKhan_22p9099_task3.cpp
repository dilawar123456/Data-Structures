#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node(char val)
    {
        data = val;
        next = NULL;
    }
};
class Stack
{
    Node *top;
    int length;

public:
    Stack()
    {
        top = NULL;
        length = 0;
    }
    bool Isempty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getLength()
    {
        return length;
    }
    void Push(char val)
    {
        Node *n = new Node(val);
        if(top==NULL)
        {
            top=n;
        }
        else 
        {
            n->next=top;
            top=n;
        }
        length++;
    }
    char pop()
    {
        if(Isempty())
        {
            cout<<"Pop Under flow"<<endl;
            
        }
        Node *temp=top;
        char val=top->data;
        top=top->next;
        delete temp;
        length--;
        return val;

    }
    void Display()
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;

        }
        cout<<endl;
    }
};
int main()
{
    int choice ;
    string str;
    Stack s1;
    Stack s2;
    
    cout <<"Please Enter the string "<<endl;
    getline(cin>>ws,str);
    for(int i=str.length();i>=0;i--)
    {
        s1.Push(str[i]);
    }
   
    
    while(1)
    {
        cout<<"Please select an option"<<endl;
        cout<<"1- Undo "<<endl;
        cout<<"2- Redo "<<endl;
        cout<<"3- Exit "<<endl;
        cin>>choice;
        if (choice==1)
        {
            int temp=s1.pop();
            s2.Push(temp);
            
        }
        else if (choice ==2 )
        {
            int temp=s2.pop();
            s1.Push(temp);
        }
        else if (choice ==3 )
        {
            cout<<"Program Exited Successfully "<<endl;
            return 0;
        }
       
       s1.Display();

       
    }
}