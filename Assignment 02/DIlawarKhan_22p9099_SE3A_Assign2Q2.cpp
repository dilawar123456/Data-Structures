#include <iostream>
using namespace std;
// implementing a list based stack
class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
    }
};
class Stack
{
    Node *head;
    int length;

public:
    Stack()
    {
        head = NULL;
        length = 0;
    }
    void Push(char val)
    {
        Node *n = new Node(val);

        n->next = head;
        head = n;
        length++;
    }
    char POP()
    {
        char temp = head->data;
        Node *curr = head;
        head = head->next;
        delete curr;
        length--;
        return temp;
    }
    bool Isempty()
    {
        if(length==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    char TOP()
    {
        if(head!=NULL)
        return head->data;
    }
    bool Bracket_match(string str)
    {
        char* ptr=&str[0];
        for(int i=0;i<str.length();i++)
        {
            if (*ptr==')' && TOP()=='(')
            {
                POP();
            }
            else if(*ptr== '}' && TOP()=='{')
            {
                POP();
            }
             else if(*ptr== ']' && TOP()=='[')
            {
                POP();
            }
            else if(*ptr== '(' || *ptr== '[' || *ptr== '{' || *ptr== ')' || *ptr== ']' || *ptr== '}' )
            {
                Push(*ptr);
            }
            ptr++;
        }
        if(length==0)
        {
        
            return true ;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Stack s1;
    string str;
    cout<<"Please enter a string "<<endl;
    getline(cin>>ws,str);
    if(s1.Bracket_match(str))
    {
        cout<<"True "<<endl;

    }
    else if(s1.Bracket_match(str)!=true)
    {
        cout<<"False"<<endl;
    }
}