#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[])
{
    int comparisons = 0;
    // implement the bubble sort logic here
    // display the array after each pass (inner loop)

    for (int i = 0; i < size - 1; i++)
    {

        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {

                swap(arr[j - 1], arr[j]);
                cout << "Array after pass :-" << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << "\t";
                }
                cout << endl;
                comparisons++;
            }
        }
    }
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[])
{
    int comparisons = 0;
    // implement the selection sort logic here
    // display the array after each pass (inner loop)
    for (int i = 0; i < size; i++)
    {
        int min = i;

        for (int j = i; j < size - 1; j++)
        {
            if (arr[min] > arr[j + 1])
            {
                min = j + 1;
            }
        }
        cout << "Array after pass :-" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
        comparisons++;
        swap(arr[min], arr[i]);
    }
    cout << "Selection Sort Comparisons: " << comparisons << endl;
}

void insertionSort(int size, int arr[])
{
    int comparisons = 0;
    // implement the insertion sort logic here
    // display the array after each pass (inner loop)
    for(int i=0;i<size;i++)
    {
        int temp=arr[i];
        int j=i-1;

        while(arr[j]>temp && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LeftArr[n1];
    int RightArr[n2];

    for (i = 0; i < n1; i++)
    {
        LeftArr[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        RightArr[j] = arr[(mid + 1) + j];
    }
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            arr[k] = LeftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = RightArr[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons)
{
    // implement the recursive binary search logic here
    if (left <= right)
    {
        comparisons++;
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return key;
        }
        else if (key > arr[mid])
        {
            return binarySearchRecursive(arr, mid + 1, right, key, comparisons);
        }
        else if (key < arr[mid])
        {
            return binarySearchRecursive(arr, left, mid - 1, key, comparisons);
        }
    }
    else
    {
        return -1;
    }
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons)
{
    int mid = size/2;
    while (mid >= 0 && mid < size)
    {
        comparisons++;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(key>arr[mid])
        {
            int temp=mid/2;
            if(temp==0)
            {
                temp=1;
            }
            
            mid=mid+temp;
        }
        else if(key<arr[mid])
        {
            int temp=mid/2;
            if(temp==0)
            {
                temp=1;
            }
            mid=mid-temp;
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

    // Display the menuv
    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Binary Search (Recursive)\n";
    cout << "6. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(size, arr);
        break;
    case 2:
        selectionSort(size, arr);
        break;
    case 3:
        insertionSort(size, arr);
        display(size, arr);
        break;
    case 4:
        mergeSort(arr, 0, size - 1);
        display(size, arr);
        break;
    case 5:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = binarySearchRecursive(arr, 0, size - 1, key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
        break;
    }
    case 6:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = binarySearchIterative(arr, size, key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
        break;
    }
    default:
        cout << "Invalid choice\n";
    }

    return 0;
}