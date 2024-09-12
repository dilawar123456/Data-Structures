#include <iostream>
using namespace std;
// implementing a list based stack
class Node
{
public:
    int data;
    Node *next;
    Node(int  data)
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
    void Push(int val)
    {
        Node *n = new Node(val);

        n->next = head;
        head = n;
        length++;
    }
    char POP()
    {
        if(length==0)
        {
            cout<<"Stack Underflow "<<endl;
            return 0;
        }
        int temp = head->data;
        Node *curr = head;
        head = head->next;
        delete curr;
        length--;
        return temp;
    }
    char TOP()
    {
        if(head!=NULL)
        return head->data;
    }
    int PostFix_Evaluation(string str)
    {
        int num1=0;
        int num2=0;
        int result=0;
        for(int i=0;i<str.length();i++)
        {
                char ch=str[i];
            if(ch=='+')
            {
                num2=POP();
                num1=POP();
                result=num1+num2;
                Push(result);

            }
          else  if(ch=='-')
            {
                num2=POP();
                num1=POP();
                result=num1-num2;
                Push(result);

            }
          else  if(ch=='*')
            {
                num2=POP();
                num1=POP();
                result=num1*num2;
                Push(result);

            }
          else  if(ch=='/')
            {
                num2=POP();
                num1=POP();
                result=num1/num2;
                Push(result);

            }
            else
            {
                
                int num=ch-'0';
                Push(num);

            }


        
        }
        return result;
    }
    bool PostFix_check()
    {
        if(length==1) //length=1 because result remain in the stack
        {
            return true;
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
    //only one digit numbers are acceptable
    cout<<"Please enter the postfix expression"<<endl;
    getline(cin>>ws,str);

    int num=s1.PostFix_Evaluation(str);
    if(!s1.PostFix_check())
    {
        cout<<"Incorrect postfix expression, Please enter a correct one "<<endl;
    }
    else
    {
        cout<<"The result is "<<num<<endl;
    }

    

    
}