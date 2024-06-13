#include <iostream>
using namespace std;

int Binary_Search(int arr[],int l,int r,int val,int & comparisons)
{
    if(l<=r)
    {
    int mid=(l+r)/2;

    if(arr[mid]==val)
    {
        return mid;
    }
    else if(arr[mid]<val)
    {
       return  Binary_Search(arr,mid+1,r,val,comparisons);
    }
    else if(arr[mid]>val)
    {
        return Binary_Search(arr,l,mid-1,val,comparisons);

    }
    }
    
        return -1;
    
}
int main()
{
   
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
         int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = Binary_Search(arr, 0, size , key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
}