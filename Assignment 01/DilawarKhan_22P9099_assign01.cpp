#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class List
{
    Node *head;
    int length;

public:
    List()
    {
        head = NULL;
        length = 0;
    }
    void Insert(int val, int pos)
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
        else if (head == NULL)
        {
            cout << "List is already empty " << endl;
            return;
        }
        Node *curr1 = head;
        Node *curr2 = head;
        if (pos == 1)
        {
            while (curr1->next != head)
            {
                curr1 = curr1->next;
            }
            head = head->next;
            curr1->next = head;
            delete curr2;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                curr1 = curr2;
                curr2 = curr2->next;
            }
            curr1->next = curr2->next;
            delete curr2;
        }

        length--;
    }
    int josephus(int N, int M)
    {
        for (int i = 1; i <= N; i++)
        {
            Insert(i, i);
        }
        int i = 1;

        while (length > 1)
        {
            i = i + M;
            while (i > length)
            {
                i = i - length;
            }

            Remove(i);
        }

        return head->data;
    }
};
int main()
{
    List l1;
    int M;
    int N;

    cout << "Enter the Number of People in the Circle " << endl;
    cin >> N;
    cout << "Enter the step size for Counting  " << endl;
    cin >> M;

    int temp = l1.josephus(N, M);

    cout << "The number of last person standing is " << temp << endl;
}