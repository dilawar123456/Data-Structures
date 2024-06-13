#include <iostream>
using namespace std;

void Merge(int arr[],int l,int mid,int r)
{
    int i;
    int j;
    int k=0;
    int x1=mid-l+1;
    int x2=r-mid;
    int l1[x1];
    int l2[x2];
    for(int i=0;i<x1;i++)
    {
        l1[i]=arr[l+i];
        
    }
    for(int j=0;j<x2;j++)
    {
        l2[j]=arr[(mid+1)+j];
        
    }
    i=0;
    j=0;
    k=l;
    while(i<x1 && j<x2)
    {
        if(l1[i]<=l2[j])
        {
            arr[k]=l1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=l2[j];
            k++;
            j++;
        }
    }
    while(i<x1)
    {
        arr[k]=l1[i];
        i++;
        k++;
    }
    while(j<x2)
    {
        arr[k]=l2[j];
        j++;
        k++;
    }

}
void MergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
       int mid=(l+r)/2;

       MergeSort(arr,l,mid);
       MergeSort(arr,mid+1,r);
       Merge(arr,l,mid,r);
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
    MergeSort(arr,0,3);
     cout<<"sorted array "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

}