#include <iostream>
using namespace std;
void Bubble_Sort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
            }
        }
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
    Bubble_Sort(arr, 4);
    cout << endl;
    cout << "After Sorting " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << "\t";
    }
}
