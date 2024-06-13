#include <iostream>
using namespace std;
class HashTable
{
    int size;
    int Lrange;
    int Rrange;
    int *arr;
    public:
    HashTable(int size,int Lrange,int Rrange)
    {
        this->size=size;
        this->Lrange=Lrange;
        this->Rrange=Rrange;
        arr= new int [size];
        for(int i=0;i<size;i++)
        {
            arr[i]=-1;
        }
    }
    void Insert(int val)
    {
        if(val<Lrange || val>Rrange)
        {
            cout<<"Value is out of range"<<endl;
            return;
        }
        else 
        {
            int i=val%size;
            int start=i;
            while(arr[i]!=val)
            {
            if(arr[i]==-1)
            {
                arr[i]=val;
            }
            else{
                i++;
                if(i==start)
                {
                    cout<<"The Hash table is full"<<endl;
                }
                else if (i==size-1)
                {
                    i=0;
                }

            }
            }
        }

    }
};