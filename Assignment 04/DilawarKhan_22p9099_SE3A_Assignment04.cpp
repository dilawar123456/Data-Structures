#include <iostream>
using namespace std;
class HashTable
{
    int *arr;
    int capacity;
    int length;

public:
    HashTable(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        length = 0;
        // Filling all empty indexes of array with -1
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = -1;
        }
    }
    bool IsTooFull()
    {
        int temp = (capacity * 0.7);
        if (length > temp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Rehash()
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity]; // constructing new array of twice the size of first array
        for (int i = 0; i < newCapacity; i++)
        {
            newArr[i] = -1;
        }
        int i = 0;
        int i2 = 0;
        while (i < capacity)
        {
            if (arr[i] == -1) // skipping the empty indexes
            {
                i++;
            }
            else
            {
                int temp = arr[i];
                i2 = temp % newCapacity;
                newArr[i2] = temp;
                i++;
            }
        }
        delete[] arr; // emptying the old array
        arr = NULL;
        capacity = newCapacity; // updating capacity of first array
        arr = new int[capacity];
        for (int j = 0; j < capacity; j++) // copying all values from the temporary array into the orignal array
        {
            arr[j] = newArr[j];
        }
        // the temporary array will be automatically deleted when the function ends as it's scope is just inside the function
        // so there won't be any dangling pointers or memory wastage.
    }
    void Insert(int val)
    {

        int i = val % capacity;
        int start = i;
        if (arr[i] == val)
        {
            cout << "cann't Insert same value twice" << endl;
            return;
        }
        else
        {

            while (arr[i] != val)
            {
                if (arr[i] == -1)
                {
                    arr[i] = val;
                    break;
                }
                i++;
                if (i == start)
                {
                    cout << "The Hash Table is Full " << endl;
                    return;
                }
                else if (i == capacity - 1)
                {
                    i = 0;
                }
            }
        }
        length++;
        //Rehashing will be done if the array gets too full(i.e more than 70% full) after the insertion
        if (IsTooFull())
        {
            cout << "Rehashing Done" << endl;
            Rehash();
        }
    }
    void Display()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};
int main()
{
    int size;
    int choice;
    int val;
    cout << "Please enter the size of Hashtable" << endl;
    cin >> size;

    HashTable h1(size);
    while (1)
    {
        cout << "Please Select an option " << endl;
        cout << "1- Insert value " << endl;
        cout << "2- Display HashTable" << endl;
        cout << "3- Exit " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the value to insert in Hashtable " << endl;
            cin >> val;
            h1.Insert(val);
        }
        else if (choice == 2)
        {
            cout << "HashTable :-" << endl;
            h1.Display();
        }
        else if (choice == 3)
        {
            cout << "Program Exited Successfully " << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Input " << endl;
        }
    }
}