#include <iostream>
using namespace std;
class Stack // array based
{
    int *arr;
    int capacity;
    int top;

public:
    Stack(int c)
    {
        capacity = c;
        arr = new int[c];
        top = -1;
    }
    bool Isempty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Isfull()
    {
        if (top == capacity - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << "\t";
        }
    }
    void Push(int val)
    {
        if (Isfull())
        {
            cout << "Stack overflow " << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int Pop()
    {
        if (Isempty())
        {
            cout << "Stack Underflow " << endl;
            return -1;
        }
        else
        {
            int val = arr[top];
            top--;
            return val;
        }
    }
    int Top()
    {
        return arr[top];
    }
};
void Tower_Of_Hanoi(Stack &s1, Stack &s2, Stack &s3)
{
   

   
        int i = 1;

        while (1)
        {

            if(s2.Isfull() || s3.Isfull())
            {
                return;
            }
            if (i % 3 == 1)
            {
                int temp = s1.Top();
                int temp2 = s3.Top();
                if (s3.Isempty() || temp < s3.Top())
                {
                    temp = s1.Pop();

                    s3.Push(temp);
                    cout << "Value " << temp << " moved from Stack 1 to Stack 3" << endl;
                }

                else if (s1.Isempty() || temp2 < s1.Top())
                {
                    temp = s3.Pop();

                    s1.Push(temp);
                    cout << "Value " << temp << " moved from Stack 3 to Stack 1" << endl;
                }
            }
            else if (i % 3 == 2)
            {
                int temp = s1.Top();
                int temp2 = s2.Top();
                if (s2.Isempty() || temp < s2.Top())
                {
                    temp = s1.Pop();

                    s2.Push(temp);
                    cout << "Value " << temp << " moved from Stack 1 to Stack 2" << endl;
                }

                else if (s1.Isempty() || temp2 < s1.Top())
                {
                    temp = s2.Pop();

                    s1.Push(temp);
                    cout << "Value " << temp << " moved from Stack 2 to Stack 1" << endl;
                }
            }
            else if (i % 3 == 0)
            {
                int temp = s3.Top();
                int temp2 = s2.Top();
                if (s2.Isempty() || temp < s2.Top())
                {
                    temp = s3.Pop();

                    s2.Push(temp);
                    cout << "Value " << temp << " moved from Stack 3 to Stack 2" << endl;
                }

                else if (s3.Isempty() || temp2 < s3.Top())
                {
                    temp = s2.Pop();

                    s3.Push(temp);
                    cout << "Value " << temp << " moved from Stack 2 to Stack 3" << endl;
                }
            }
            i++;
        }
    
}
int main()
{

    int disks;
    int flag;

    cout << "Enter the number of disks in First peg"<<endl;
    cin >> disks;
    // If number of disks are odd all the disks will be stored in stack 3
    //If number of disks are even all the disks will be stored in stack 2
    Stack s1(disks);
    Stack s2(disks);
    Stack s3(disks);
    for (int i = disks; i > 0; i--)
    {
        s1.Push(i);
    }    
    
    
    Tower_Of_Hanoi(s1, s2, s3);


    cout << "--------------------" << endl;
    cout << "After all moves" << endl;
    cout << "Stack 1:-" << endl;
    s1.display();
    cout<<endl;
    cout << "Stack 2:- " << endl;
    s2.display();
    cout<<endl;
    cout << "Stack 3:-" << endl;
    s3.display();


    return 0;
}