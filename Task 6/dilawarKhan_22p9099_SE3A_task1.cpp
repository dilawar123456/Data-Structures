#include <iostream>
using namespace std;
class ArrayList
{
    int *arr;
    int size;
    int length;
    int *curr;

public:
 void Tail()
    {
        curr = arr + length - 1;
    }
    void Start()
    {
        curr = &arr[0];
    }
    void Next()
    {
        curr++;
    }
    void Back()
    {
        curr--;
    }
    ArrayList(int size)
    {
        this->size = size;
        arr = new int[size];
        length = 0;
        curr = NULL;
    }
     void Insert(int val, int pos)
    {
        if (length == size)
        {
            cout << "Array is already full" << endl;
            return;
        }
        else if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else
        {

            Tail();
            for (int i = length; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                Back();
            }
            *(curr + 1) = val;
            length++;
        }
    }
    void Print()
    {
        Start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr <<"\t";
            Next();
        }
        cout << endl;
    }
    void RearrangeList()
    {
        int * curr1=&arr[0];
        int *curr2=&arr[1];
        int temp=0;

        for(int i=1;i<length-1;i++)
        {

            for(int j=1;j<length-1;j++)
            {
                if(*curr1%2!=0 && *curr2%2==0)
                {
                    temp=*curr1;
                    *curr1=*curr2;
                    *curr2=temp;
                    curr1++;
                    curr1++;
                    curr2++;
                    curr2++;
                
                }
                else
                {
                    curr2++;
                }
            }
            curr1++;
        }

    }
};
int main()
{
    //assuming that user will input equalt number of even and odd numbers
    ArrayList l1(10);
    l1.Insert(5,1);
    l1.Insert(2,2);
    l1.Insert(9,3);
    l1.Insert(4,4);
    l1.Insert(7,5);
    l1.Insert(6,6);
    l1.Insert(3,7);
    l1.Insert(8,8);
    
    l1.Print();

    l1.RearrangeList();

    l1.Print();


}