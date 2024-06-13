#include <iostream>
using namespace std;
int binarySearch(int arr[],int lb,int ub,int val)
{
    if(lb<=ub)
    {
        int mid=(lb+ub)/2;
        if(arr[mid]==val)
        {
            return mid;
        }
        else if (arr[mid]<val)
        {
            return binarySearch(arr,mid+1,ub,val);
        }
        else
        {
            return binarySearch(arr,lb,mid-1,val);
        }

    }
    else 
    {
        return -1;
    }
}
int main()
{
    int arr[]={1,2,3,5,7,9,11,13,15,16,17,19,21,24,26};
    int search;
    int index;
    cout<<"Enter the value to search"<<endl;
    cin>>search;
    index=binarySearch(arr,0,15,search);
    if(index==-1)
    {
        cout<<"value not found "<<endl;
    }
    else 
    {
        cout<<"The value is found at Index "<<index;
    }

}