#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int top;
    int capacity;
    public:
    Stack(int size)
    {
        capacity=size;
        top=-1;
        arr=new int [capacity];
    } 
    void Push(int val)
    {
        
        if(top==capacity-1)
        {
            cout<<"Stack Overflow "<<endl;
            return ;
        }
        else
        {
            top++;
            int *curr=arr+top;
            *curr=val;


        }
        
    }
    int Pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow "<<endl;
        }
        int* temp=arr+top;
        top--;
        return *temp;
    }
};
int main()
{
    string str;
   


    cout<<"Enter the string "<<endl;
    getline(cin>>ws,str);

    int length=str.length();
    Stack s1(length);
    for(int i=0;i<length;i++)
    {
        int temp=str[i];
        s1.Push(temp);
    }
    for(int i=0;i<length;i++)
    {
        str[i]=s1.Pop();
    }


    cout<<"The reversed string is "<<str<<endl;


}