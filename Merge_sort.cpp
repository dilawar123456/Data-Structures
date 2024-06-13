#include <iostream>
using namespace std;

void Merge(int arr[],int lb, int mid, int ub);//forward declaration
void Merge_sort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
    int mid=(lb+ub)/2;
    Merge_sort(arr,lb,mid);
    Merge_sort(arr,mid+1,ub);

    Merge(arr,lb,mid,ub);
    }
}
void Merge(int arr[],int lb, int mid, int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int brr[ub];
   
        while(i<=mid && j<=ub)
        {
            if(arr[i]<=arr[j])
            {
                brr[k]=arr[i];
                i++;
            }
            else
            {
                brr[k]=arr[j];
                j++;
            }
            k++;

        }
        if(i>mid)
        {
            while(j<=ub)
            {
                brr[k]=arr[j];
                j++;
                k++;
            }
        }
        else if(j>mid)
        {
            while(i<=mid)
            {
                brr[k]=arr[i];
                i++;
                k++;
            }
        } 

        for(int i=lb;i<=ub;i++)
        {
            arr[i]=brr[i];
        }
    

}

int main ()
{
    int arr[]={3,6,2,4,1,9,7,20,24,43,21,19,18,77,11};
    cout<<"Array is "<<endl;
    for(int i=0;i<15;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    Merge_sort(arr,0,15);
    cout<<"SortArray is "<<endl;
    for(int i=0;i<15;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

}