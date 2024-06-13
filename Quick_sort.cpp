#include <iostream>
using namespace std;
int Partition(int arr[],int lb, int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end= ub;

    while(start<end)
    {

        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }

    }
    swap(arr[lb],arr[end]);
    return end;
}
void Quick_sort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
        int loc= Partition(arr,lb,ub);

    Quick_sort(arr,lb,loc-1);
    Quick_sort(arr,loc+1,ub);
    }
   
}

int main ()
{
    int arr[]={3,5,1,2,10,6,21,23,11,12,16,34,45,76,87};
    cout<<"The array is "<<endl;
    for(int i=0;i<15;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    Quick_sort(arr,0,15);
        cout<<"The Sorted array is "<<endl;
    for(int i=0;i<15;i++)
    {
        cout<<arr[i]<<"\t";
    }


}
