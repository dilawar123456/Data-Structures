#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int top;
    int capacity;
    public:
    Stack(int capacity)
    {
        this->capacity=capacity;
        arr=new int [capacity];
        top=-1;
    }
    void Push(int val)
    {
        if(top==capacity-1)
        {
            cout<<"Stack overflow "<<endl;
            return ;
        }
        else{
        top++;
        arr[top]=val;
        }
    }
    int pop()
    {
        if(top<0)
        {
            cout<<"stack underflow "<<endl;
            return 0;

        }
        else{
        
        int temp=arr[top];
        top--;
        return temp;
        }
    }
    int get()
    {
        return arr[top];
    }

};
int main ()
{
    int x;
    int val;
    Stack s1(10);

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
            cout<<"value popped "<<s1.pop()<<endl;
        }
        else if(x==3)
        {
            cout<<"value :"<<s1.get()<<endl;
        }
        else if (x==4)
        {
            cout<<"program exited successfully "<<endl;
            return 0;
        }
    }
}