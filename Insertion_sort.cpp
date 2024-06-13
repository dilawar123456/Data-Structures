#include <iostream>
using namespace std;
void Insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int arr[] = {4, 23, 12, 43, 21, 54, 65, 76, 98, 78, 11, 13, 12, 16, 64};
    cout << "The array is " << endl;
    for (int i = 0; i < 15; i++)

    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    Insertion_sort(arr,15);
    cout << "The Sorted array is" << endl;
    for (int i = 0; i < 15; i++)

    {
        cout << arr[i] << "\t";
    }
}