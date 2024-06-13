#include <iostream>
using namespace std;
int Selection_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {


        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }


}
int main()
{
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<endl;
        cin>>arr[i];
    }
    cout<<"The array is "<<endl;
    for( int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    cout<<"The array after sorting is "<<endl;
    Selection_sort(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}