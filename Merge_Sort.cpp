#include <iostream>
using namespace std;
void Merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int LeftArr[n1];
    int RightArr[n2];

    
    for( i=0;i<n1;i++)
    {
        LeftArr[i]=arr[l+i];
    }
    for( j=0;j<n2;j++)
    {
        RightArr[j]=arr[(m+1)+j];
    }

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(LeftArr[i]>=RightArr[j])
        {
            arr[k]=RightArr[j];
            k++;
            j++;
        }
        else
        {
            arr[k]=LeftArr[i];
            i++;
            k++;
        }

    }
    while(i<n1)
    {
        arr[k]=LeftArr[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=RightArr[j];
        j++;
        k++;
    }



}
void Merge_Sort(int arr[],int l, int r)
{
    if(l<r)
    {
    int mid=(l+r)/2;
    Merge_Sort(arr,l,mid);
    Merge_Sort(arr,mid+1,r);
    Merge(arr,l,mid,r);
    }
    
}

int main()
{
    int *arr = new int[4];
    arr[0] = 65;
    arr[1] = 32;
    arr[2] = 50;
    arr[3] = 80;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << "\t";
    }
    Merge_Sort(arr,0,4);
    cout << endl;
    cout << "After Sorting " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << "\t";
    }
}