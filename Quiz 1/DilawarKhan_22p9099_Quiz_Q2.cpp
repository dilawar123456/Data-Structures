#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    Node *top;
    int length;

public:
    Stack()
    {
        top = NULL;
        length = 0;
    }
    bool IsEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push(char val)
    {
        // pushing at head
        Node *n = new Node(val);
        n->next = top;
        top = n;
        length++;
    }
    char Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow " << endl;
        }
        else
        {
            char temp = top->data;
            Node *curr = top;
            top = top->next;

            delete curr;
            length--;
            return temp;
        }
    }
    char Top()
    {
        return top->data;
    }
};

int main()
{
    int choice;
    char ch;
    Stack s1;

    cout << "Welcome to the Cave " << endl;
    cout << "Mark your location so that you can go back whenever you see a mummy " << endl;

    while (1)
    {
        cout << "Enter a choice " << endl;
        cout << "1- Go forward in the game " << endl;
        cout << "2- Go back " << endl;
        cout << "3- Run from the cave " << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Mark your current location, so that you can go back" << endl;
            cout << "Enter the name of your current location " << endl;
            cin >> ch;
            s1.Push(ch);
        }
        else if (choice == 2)
        {
            ch = s1.Pop();
            cout << "You are now at : " << ch << endl;
        }
        else if (choice == 3)
        {
            while (!s1.IsEmpty())
            {
                ch = s1.Pop();
                cout << "You are now at : " << ch << endl;
            }
            cout<<"You Successfully ran away from the cave "<<endl;

            return 0;
        }
        else
        {
            cout<<"Invalid Input "<<endl;
        }
    }
}