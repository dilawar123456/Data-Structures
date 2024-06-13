
#include <iostream>
using namespace std;
class ArrayList
{
    int *arr;
    int size;
    int length;
    int *curr;

public:
    ArrayList(int size)
    {
        this->size = size;
        arr = new int[size];
        length = 0;
        curr = NULL;
    }
    void Start()
    {
        curr = arr;
        //or curr = &arr[0];
    }
    void Tail()
    {
        curr = arr + length - 1;
    }
    void Next()
    {
        curr++;
    }
    void Back()
    {
        curr--;
    }
    void clear()
    {
        length = 0;
    }
    void Insert(int val, int pos)
    {
        if (length == size)
        {
            cout << "Array is already full" << endl;
            return;
        }
        else if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else
        {
           
            Tail();
            for (int i = length; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                Back();
            }
            *(curr + 1) = val;
            length++;
        }
    }
    void Remove(int pos)
    {
        if (length == 0)
        {
            cout << "The list is already empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        else
        {
            Start();
            for (int i = 1; i < pos; i++)
            {
                Next();
            }
            for (int i = pos; i < length; i++)
            {
                *curr = *(curr + 1);
                Next();
            }
            length--;
        }
    }
    int Get(int index)
    {
        curr = arr + index - 1;
        return *curr;
    }
    void Update(int pos, int val)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        else
        {
            curr = arr + pos - 1;
            *curr = val;
        }
    }
    int Find(int val)
    {
        Start();
        for (int i = 1; i < length; i++)
        {
            if (*curr == val)
            {
                return i;
            }
            Next();
        }
        return -1;
    }
    int Length()
    {
        return length;
    }
    void Copy(ArrayList l2)
    {
        if (size < l2.length)
        {
            cout << "Not enough capacity " << endl;
            return;
        }
        else
        {
            for (int i = 0; i < l2.length; i++)
            {
                int val = l2.Get(i + 1);
                Insert(val, i + 1);
            }
        }
    }
    void Print()
    {
        Start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr << "-->";
            Next();
        }
        cout << endl;
    }
};
int main()
{
    int x;
    int size;
    int val;
    int pos;

    cout << "Enter the size of list " << endl;
    cin >> size;
    ArrayList l1(size);

    while (1)
    {
        cout << "Please Select An Option " << endl;
        cout << "1- Insert " << endl;
        cout << "2- Remove " << endl;
        cout << "3- Clear " << endl;
        cout << "4- Get " << endl;
        cout << "5- Update " << endl;
        cout << "6- Find " << endl;
        cout << "7- Length " << endl;
        cout << "8- Copy " << endl;
        cout << "9- Display" << endl;
        cout << "10- Exit " << endl;
        cin >> x;
        if (x == 1)
        {
            cout << "Enter The value to Insert " << endl;
            cin >> val;
            cout << "Enter the position where you want to insert value " << endl;
            cin >> pos;
            l1.Insert(val, pos);
        }
        else if (x == 2)
        {
            cout << "Enter the position which you want to remove " << endl;
            cin >> pos;
            l1.Remove(pos);
        }
        else if (x == 3)
        {
            l1.clear();
            cout << "List Cleared " << endl;
        }
        else if (x == 4)
        {
            cout << "Enter The position of which you want value " << endl;
            cin >> pos;
            cout << "The value at position " << pos << " is " << l1.Get(pos) << endl;
        }
        else if (x == 5)
        {
            cout << "Enter the position of which you want to update value " << endl;
            cin >> pos;
            cout << "Enter the updated value " << endl;
            cin >> val;
            l1.Update(pos, val);
        }
        else if (x == 6)
        {
            cout << "Enter the value you want to find " << endl;
            cin >> val;
            int temp = l1.Find(val);
            if (temp == -1)
            {
                cout << "Value not found " << endl;
            }
            else
            {
                cout << "value found at position " << temp << endl;
            }
        }
        else if (x == 7)
        {
            cout << "The length of the list is " << l1.Length() << endl;
        }
        else if (x == 8)
        {
            ArrayList l2(l1.Length());
            l2.Copy(l1);
            cout << "Values Copied " << endl;
            cout << "Old List:- " << endl;
            l1.Print();
            cout << "New List:- " << endl;
            l2.Print();
        }
        else if (x == 9)
        {
            cout << "List :- " << endl;
            l1.Print();
        }
        else if (x == 10)
        {
            cout << "Program Exited Succesfully " << endl;
            return 0;
        }
    }
}