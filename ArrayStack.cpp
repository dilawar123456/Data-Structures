#include <iostream>
using namespace std;
class ArrayList
{
    int *arr;
    int capacity;
    int length;

public:
    ArrayList(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        length = 0;
    }
    void Print()
    {
        int *curr=&arr[0];
        for(int i=0;i<length ;i++)
        {
            cout<<*curr<<"\t";
            curr++;
        }
    }
    bool IsFull()
    {
        if (length == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool IsEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Insert(int val, int pos)
    {
        if(IsFull())
        {
            cout<<"List already full"<<endl;
            return ;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        else{
        int *curr = arr + length - 1;
        
            for (int i = length; i >= pos; i++)
            {
                *(curr+1)=*curr;
                curr--;
            }
            *(curr+1)=val;
            length++;
        }
        
    }
    int get(int pos)
    {
        int *curr=arr+pos-1;
        return *curr;
    }
    void Remove(int pos)
    {
        if(IsEmpty())
        {
            cout<<"List already empty"<<endl;
            return ;
        }
        if(pos<1 || pos>length)
        {
            cout<<"Invalid Position "<<endl;
            return ;
        }
        else
        {
            int *curr=&arr[0];
            for(int i=1;i<pos;i++)
            {

                curr++;
            }
            for(int i=pos;i<length;i++)
            {
                *curr=*(curr+1);
                curr++;
            }
            length--;

        }
    }
};
class Stack:public ArrayList
{
    int top;
    public:
    Stack(int s):ArrayList(s)
    {
        top=0;
    }
    void Push(int val)
    {
        if(IsFull())
        {
            cout<<"Stack overflow "<<endl;
            return ;
        }
        else 
        {
            top++;
            Insert(val,top);
        }
    }
    int Pop()
    {
        int temp=get(top);
        Remove(top);
        top--;
        return temp;
    }
    int Top()
    {
        int temp=get(top);
        return temp;
    }

};
int main()
{
    Stack s1(10);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    s1.Push(6);
    
    s1.Print();
    cout<<endl;
    cout<<s1.Pop();
    cout<<s1.Pop();
    cout<<endl;
    s1.Print();

}