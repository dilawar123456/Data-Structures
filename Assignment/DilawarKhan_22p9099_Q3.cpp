#include <iostream>
using namespace std;
class Student
{
    string name;
    int merit;

public:
    Student(string name = "", int merit = 0)
    {
        this->name = name;
        this->merit = merit;
    }
    string getName()
    {
        return name;
    }
    int getMerit()
    {
        return merit;
    }
};
class Node
{
public:
    Student data;
    Node *next;
    Node(Student data)
    {
        this->data = data;
        next = NULL;
    }
};
class AdmissionQueue
{
    Node *head;
    int length;

public:
    AdmissionQueue()
    {
        head = NULL;
        length = 0;
    }
    void Enqueue(Student s1)
    {
        Node *n = new Node(s1);
        if (head == NULL)
        {
            head = n;
            length++;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = n;
            length++;
        }
    }
    Student Dequeue()
    {
        if (Isempty())
        {
            cout << "Queue Underflow " << endl;
        }
        else
        {
            Student temp = head->data;
            Node *curr = head;
            head = head->next;
            delete curr;
            length--;
            return temp;
        }
    }
    bool Isempty()
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
    void Display()
    {
        Node *curr = head;
        int i=1;
        while (curr != NULL)
        {
            cout<<"STUDENT "<<i<<" :-"<<endl;
            cout << "Student's Name : " << curr->data.getName() << endl;
            cout << "Studet's Merit : " << curr->data.getMerit() << endl;
            cout << "-----------------" << endl;
            i++;
            curr = curr->next;
        }
    }
    Student Next()
    {
        return head->data;
    }
    int getLength()
    {
        return length;
    }
};
int main()
{
    AdmissionQueue q1;
    AdmissionQueue q2;
    AdmissionQueue q3;
    int choice;
    string name;
    int merit;
    int insert = 0;
    int x;

    while (1)
    {
        cout << "Please select an option " << endl;
        cout << "1- Add Students to Queue " << endl;
        cout << "2- Process Admissions " << endl;
        cout << "3- Check Queue Status " << endl;
        cout << "4- Chech Who is Next " << endl;
        cout << "5- Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter name of student " << endl;
            getline(cin >> ws, name);
            cout << "Enter merit of student " << endl;
            cin >> merit;
            Student s1(name, merit);
            if (insert > 2)
            {
                insert = 0;
            }
            if (insert == 0)
            {
                q1.Enqueue(s1);
            }
            else if (insert == 1)
            {
                q2.Enqueue(s1);
            }
            else if (insert == 2)
            {
                q3.Enqueue(s1);
            }
            insert++;
        }

        else if (choice == 2)
        {
            while(!q1.Isempty())
            {
                Student temp=q1.Dequeue();
                if (temp.getMerit()>50)
                {
                    cout<<temp.getName()<<"'s admission is secured "<<endl;
                }
                else 
                {
                   cout<< temp.getName()<<" was unable to secure position "<<endl;
                }
            }
            while(!q2.Isempty())
            {
                Student temp=q2.Dequeue();
                if (temp.getMerit()>50)
                {
                    cout<<temp.getName()<<"'s admission is secured "<<endl;
                }
                else 
                {
                   cout<< temp.getName()<<" was unable to secure position "<<endl;
                }
            }
            while(!q3.Isempty())
            {
                Student temp=q3.Dequeue();
                if (temp.getMerit()>=50)
                {
                    cout<<temp.getName()<<"'s admission is secured "<<endl;
                }
                else 
                {
                   cout<< temp.getName()<<" was unable to secure position "<<endl;
                }
            }
        }
        else if (choice == 3)
        {
                cout<<"**********************"<<endl;
                cout<<"Queue 1 :-"<<endl;
                cout<<"Number of Students : "<<q1.getLength()<<endl;
                q1.Display();
                cout<<"**********************"<<endl;
                cout<<"Queue 2 :-"<<endl;
                cout<<"Number of Students : "<<q2.getLength()<<endl;
                q2.Display();
                cout<<"**********************"<<endl;
                cout<<"Queue 3 :-"<<endl;
                cout<<"Number of Students : "<<q3.getLength()<<endl;
                q3.Display();
            

        }
        else if (choice ==4 )
        {
            cout<<"Select queue "<<endl;
            cout<<"1- Queue 1 "<<endl;
            cout<<"2- Queue 2"<<endl;
            cout<<"3- Queue 3"<<endl;
            cin>>x;
            if(x==1)
            {
                cout<<"The next student is Queue 1 is "<<q1.Next().getName()<<endl;
            }
            else if(x==2)
            {
                cout<<"The next student is Queue 2 is "<<q2.Next().getName()<<endl;
            }
            else if(x==3)
            {
                cout<<"The next student is Queue 3 is "<<q3.Next().getName()<<endl;
            }
            

        }
        else if( choice ==5 )
        {
            cout<<"Program exited successfully "<<endl;
            return 0;
        }
        else
        {
            cout<<"Invalid Input "<<endl;
        }

        
    }
}