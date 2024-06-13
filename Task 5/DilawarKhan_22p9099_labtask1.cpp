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
    int a;
    int b;
    Stack s1(2);
    cout <<"Enter value of a"<<endl;
    cin>>a;
    cout<<"Enter value of b"<<endl;
    cin>>b;
    cout<<"Value of a before swap "<<a<<endl;
    cout<<"Value of b before swap "<<b<<endl<<endl<<endl;
    s1.Push(a);
    s1.Push(b);

    a=s1.Pop();
    b=s1.Pop();
    cout<<"Value of a before swap "<<a<<endl;
    cout<<"Value of b before swap "<<b;

}
