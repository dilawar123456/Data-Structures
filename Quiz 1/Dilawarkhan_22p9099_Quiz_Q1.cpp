#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node(string data)
    {
        this->data = data;
        next = NULL;
    }
};
class CircularList
{
    Node *head;
    int length;

public:
    CircularList()
    {
        head = NULL;
        length = 0;
    }
    void Insert(string val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        else if (pos == 1)
        {
            Node *n = new Node(val);
            if (head == NULL)
            {
                head = n;
                head->next = head;
            }
            else
            {
                Node *curr = head;
                while (curr->next != head)
                {
                    curr = curr->next;
                }
                n->next = head;
                head = n;
                curr->next = head;
            }
        }
        else
        {
            Node *n = new Node(val);
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
    void Remove(int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        else if (length == 0)
        {
            cout << "List is already empty " << endl;
            return;
        }
        else if (pos == 1)
        {
            Node *curr = head;
            Node *tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;

            delete curr;
            length--;
            if (length == 0)
            {
                head = NULL; // To avoid dangling pointer
            }
        }
        else
        {
            Node *curr1 = head;
            Node *curr2 = head;
            for (int i = 1; i < pos; i++)
            {
                curr1 = curr2;
                curr2 = curr2->next;
            }
            curr1->next = curr2->next;
            delete curr2;
            length--;
        }
    }
    void Display()
    {
        Node *curr = head;
        int temp = 1;
        do
        {
            cout << temp << "). " << curr->data << endl;
            curr = curr->next;
            temp++;
        } while (curr != head);
    }
    void Traverse(int k)
    {
        while (k > length)
        {
            k = k - length;
        }
        Node *curr = head;
        for (int i = 1; i < k; i++)
        {
            curr = curr->next;
        }
        cout << curr->data;
    }
    int getlength()
    {
        return length;
    }
    string getName(int k)
    {
        Node *curr = head;
        for (int i = 1; i < k; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }
};

int main()
{
    int choice;
    int k = 1; // for keeping track of traverse function
    CircularList l1;

    l1.Insert("Creepy Carol", 1);
    l1.Insert("Spooky Sophia", 2);
    l1.Insert("Grim the Dark", 3);
    l1.Insert("Gothic Queen", 4);
    l1.Insert("Ghostly Bella", 5);

    while (1)
    {
        cout << "Please select an option " << endl;
        cout << "1- Traverse Wizards one by one" << endl;
        cout << "2- Start Game" << endl;
        cout << "3- Exit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            l1.Traverse(k);
            cout << endl;
            k++;
            while (1)
            {
                cout << "1- Next " << endl;
                cout << "2- Go back to main menu " << endl;
                cin >> choice;
                if (choice == 1)
                {
                    l1.Traverse(k);
                    cout << endl;
                    k++;
                }
                else if (choice == 2)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Input " << endl;
                }
            }
        }
        else if (choice == 2)
        {
            string str;
            while (l1.getlength() >= 2)
            {
                l1.Display();

                int r = rand() % (l1.getlength()) + 1;
                str = l1.getName(r);
                l1.Remove(r);

                cout << "Random Number : " << r << endl;
                cout << str << " removed from the game" << endl;
            }
            str = l1.getName(1);
            cout << "Winner is " << str << endl;
            cout << "Will Now drink the Potion" << endl;
            return 0;
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
