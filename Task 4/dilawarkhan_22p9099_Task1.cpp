#include <iostream>
using namespace std;
class Node
{
public:
    string data;
    bool completion;
    Node *next;
    Node *prev;
    Node(string data)
    {
        this->data = data;
        completion = false;
        next = NULL;
        prev = NULL;
    }
};
class List
{
    int length;
    Node *head;

public:
    List()
    {
        head = NULL;
        length = 0;
    }
    void Insert(string val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "invalid Position " << endl;
            return;
        }
        Node *n = new Node(val);

        if (pos == 1)
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                n->next = head;
                head->prev = n;
                head = n;
            }
        }
        else
        {
            Node *curr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            if(curr->next!=NULL)
            {curr->next->prev = n;}
            n->prev = curr;
            curr->next = n;
        }
        length++;
    }
    void MarkCompleted(int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos; i++)
            {
                curr = curr->next;
            }
            curr->completion = true;
        }
    }

    void Remove(int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Length" << endl;
            return;
        }
        else if (pos == 1)
        {
            Node *curr = head;
            curr = curr->next;
            delete head;
            head = curr;
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
            if(curr2->next!=NULL)
            {curr2->next->prev = curr1;}
            delete curr2;
        }
        length--;
    }
    void RemoveCompleted()
    {
        Node *curr = head;
        Node* curr2=head;
        int i=1;
        while(curr!=NULL)
        {
            curr2=curr->next;
            if(curr->completion==true)
            {
                Remove(i);
                i--;
            }
            curr=curr2;

            i++;
        }
    }
    void Print(int check)
    {
        if(check==1)
        {
        Node* curr=head;
        int i=1;
        while(curr!=NULL)
        {
            
            cout<<i<<") "<<curr->data<<" ";
            if(curr->completion==false)
            {
                cout<<" - Not Completed "<<endl;
            }
            else 
            {
                cout<<" - Completed"<<endl;
            }
            curr=curr->next;
            i++;
        }

        }
        else if(check==2)
        {
        Node* curr=head;
        int i=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        while(curr!=NULL)
        {
            
            cout<<i<<") "<<curr->data<<" ";
            if(curr->completion==false)
            {
                cout<<" - Not Completed "<<endl;
            }
            else 
            {
                cout<<" - Completed"<<endl;
            }
            curr=curr->prev;
            i++;
        }   
        }
    }
    ~List()
    {
        Node * curr=head;
        Node* curr2=head;
        while(curr!=NULL)
        {
            curr2=curr->next;
            delete curr;
            curr=curr2;

        }
        head=NULL;
    }
};
int main()
{
    int x;
    string task;  
    int pos;
    int priority;
    List l1;

    while (1)
    {
        cout <<"Please Select An Option "<<endl;
        cout<<"1- Add Task "<<endl;
        cout<<"2- Mark as completed "<<endl;
        cout<<"3- Remove Completed Tasks"<<endl;
        cout<<"4- Display To Do list "<<endl;
        cout<<"5- Exit "<<endl;
        cin>>x;

        if(x==1)
        {
            cout<<"Enter the title of task "<<endl;
            getline(cin>>ws,task);
            cout<<"Enter the priority number "<<endl;
            cin>>priority;
            l1.Insert(task,priority);
        }
        else if( x==2)
        {
            l1.Print(1);
            cout<<"Enter the position of task to mark it as completed "<<endl;
            cin>>pos;
            l1.MarkCompleted(pos);

        }
        else if(x==3)
        {
            l1.RemoveCompleted();
            cout<<"All completed tasks successfully removed "<<endl;
        }
        else if (x==4)
        {
            cout<<"1- Display in forward direction "<<endl;
            cout<<"2- Display in reverse direction "<<endl;
            cin>>pos;
            l1.Print(pos);
        }
        else if(x==5)
        {
            cout<<"Program Exited successfully "<<endl;
            return 0;
        }
    }
}