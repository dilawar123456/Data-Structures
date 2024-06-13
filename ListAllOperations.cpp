
#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class List
{
    int length;
    Node *head;

public:
    List();
    void Insert(int val, int pos);
    void Print();
    void Remove(int pos);
    int Search(int val);
    void Update(int val, int pos);
    int Get(int pos);
    void Copy(List l2);
    int GetLength();
};
List::List()
{
    length = 0;
    head = NULL;
}
void List::Insert(int val, int pos)
{
    if (pos < 1 || pos > length + 1)
    {
        cout << "Invalid Position " << endl;
        return;
    }
    else
    {
        Node *n = new Node(val);
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *curr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
}
void List::Print()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "-->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}
void List::Remove(int pos)
{
    if (pos < 1 || pos > length)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    else
    {
        Node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            Node *curr2 = head;
            for (int i = 1; i < pos; i++)
            {
                curr = curr2;
                curr2 = curr2->next;
            }
            curr->next = curr2->next;
            delete curr2;
        }
        length--;
    }
}
int List::Search(int val)
{
    Node *curr = head;
    for (int i = 1; i <= length; i++)
    {
        if (curr->data == val)
        {
            return i;
        }
        curr = curr->next;
    }
    return -1;
}
void List::Update(int val, int pos)
{
    Node *curr = head;
    for (int i = 1; i < pos; i++)
    {
        curr = curr->next;
    }
    curr->data = val;
}
int List::Get(int pos)
{
    if (pos < 1 || pos > length)
    {
        cout << "Invalid Input" << endl;
        return -1;
    }
    else
    {

        Node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }
}
int List::GetLength()
{
    return length;
}

int main()
{
    int x;
    int val;
    int pos;
    List l1;
    while (1)
    {
        cout << "PLEASE SELECT AN OPTION" << endl;
        cout << "1- Insert" << endl;
        cout << "2- Remove" << endl;
        cout << "3- Search" << endl;
        cout << "4- Update" << endl;
        cout << "5- Get value " << endl;
        cout << "6- Get Length" << endl;
        cout << "7- Print " << endl;
        cout << "8- Exit" << endl;
        cin >> x;
        if (x == 1)
        {
            cout << "Please enter a value " << endl;
            cin >> val;
            cout << "Enter the position where you want to insert value " << endl;
            cin >> pos;
            l1.Insert(val, pos);
        }
        else if (x == 2)
        {
            cout << "Enter the position to remove " << endl;
            cin >> pos;
            l1.Remove(pos);
        }
        else if (x == 3)
        {
            cout << "Please enter a value to search" << endl;
            cin >> val;
            int temp = l1.Search(val);
            if (temp == -1)
            {
                cout << "value not found " << endl;
            }
            else
            {
                cout << val << " found at position " << temp << endl;
            }
        }
        else if (x == 4)
        {
            cout << "Please enter updated value " << endl;
            cin >> val;
            cout << "Enter the position where you want to update value " << endl;
            cin >> pos;
            l1.Update(val, pos);
        }
        else if (x == 5)
        {
            cout << "Enter the position to get it's value " << endl;
            cin >> pos;
            int temp = l1.Get(pos);
            if (temp == -1)
            {
                cout << "value not found " << endl;
            }
            else
            {
                cout << "The value at position " << pos << " is " << temp << endl;
            }
        }
        else if (x == 6)
        {
            cout << "The length of list is " << l1.GetLength() << endl;
        }
        else if (x == 7)
        {
            cout << "List :-" << endl;
            l1.Print();
        }
        else if (x == 8)
        {
            cout << "program exited successfully " << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Input " << endl;
        }
    }
}