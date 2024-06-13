#include <iostream>
using namespace std;
void Selection_Sort(int arr[],int size)
{   

    for(int i=0;i<size-1;i++)
    {
        int min=i;


        for(int j=i;j<size-1;j++ )
        {
            if(arr[min]>arr[j+1])
            {
                min=j+1;
                
            }

        }
        swap(arr[min],arr[i]);
    }

}
int main()
{
    int* arr= new int [4];
    arr[0]=65;
    arr[1]=32;
    arr[2]=50;
    arr[3]=80;
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<"\t";
    }
    Selection_Sort(arr,4);
    cout<<endl;
    cout<<"After Sorting "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<"\t";
    }

}
