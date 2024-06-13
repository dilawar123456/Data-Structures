#include<iostream>
using namespace std;
void Bubble_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {


        for(int j=1;j<size-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                swap(arr[j-1],arr[j]);
            }
        }
    }
}
int main()
{
    int size=8;
    int arr[size]={4,1,8,32,12,3,5,34};
    cout<<"The array is"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    Bubble_sort(arr,size);
    cout<<"The Sorted array is"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}