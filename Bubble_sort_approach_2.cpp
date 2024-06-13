#include <iostream>
using namespace std;
void BubbleSort(int arr[],int size)
{
    for(int i=0;i<=(size/2);i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

}
int main()
{
    int arr[4]={6,1,5,3};
    cout<<"Unsorted array "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    BubbleSort(arr,4);
     cout<<"sorted array "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}