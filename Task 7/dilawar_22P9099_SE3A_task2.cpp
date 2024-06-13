#include <iostream>
using namespace std;
class Node
{
    public:
    string data;
    Node* next;
    Node(string data)
    {
        this->data=data;
        next=NULL;
    }

};
class Queue
{
    Node* head;
    int length;
    public:
    Queue()
    {
        head=NULL;
        length=0;
    }
    void Enqueue(string val)
    {
        Node* n=new Node(val);
        if(head==NULL)
        {
            head=n;
        }
        else
        {
            Node* curr=head;
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            curr->next=n;
        }
        length++;

    }
    
    string Dequeue()
    {
        if(length==0)
        {
            return " ";
        }
        else
        {
        string temp=head->data;
        Node* curr=head;
        head=head->next;
        
        delete curr;
        length--;
        return temp;
        }

    }
    string gethead()
    {
        return head->data;

    }
    bool Isempty()
    {
        if(length==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    


};
int main()
{
    Queue Ticket_purchasing;
    Queue Roller_coaster;
    Queue Round_wheel;
    Queue Motion_Ride;
    int x;
    string name;

    while(1)
    {
        cout<<"Please select a choice "<<endl;
        cout<<"1- Enter a visitor in ticket purchasing queue "<<endl;
        cout<<"2- Sell a ticket "<<endl;
        cout<<"3- Process all queues "<<endl;
        cin>>x;
       

        if(x==1)
        {
            cout<<"Enter the visitor's name "<<endl;
            getline(cin>>ws,name);
            Ticket_purchasing.Enqueue(name);
        }
        else if(x==2)
        {
            if(Ticket_purchasing.Isempty()==true)
            {
                cout<<"No more visitors in the queue "<<endl;

            }
            else
            {
            name=Ticket_purchasing.Dequeue();
            cout<<"Now selling Ticket to "<<name<<endl;
            cout<<"Which attraction's ticket "<<name<<" wants ?"<<endl;
            cout<<"1- Roller Coaster "<<endl;
            cout<<"2- Round Wheel "<<endl;
            cout<<"3- Motion Ride "<<endl;
            cin>>x;
            if(x==1)
            {
                Roller_coaster.Enqueue(name);
            }
            else if (x==2)
            {
                Round_wheel.Enqueue(name);
            }
            else if (x==3)
            {
                Motion_Ride.Enqueue(name);
            }
            else if(x==4)
            {
                cout<<"Invalid Input "<<endl;

            }
            }


    }
        else if(x==3)
        {
            while(!Roller_coaster.Isempty())
            {
                name=Roller_coaster.Dequeue();
                cout<<"Visitor "<<name<<" now enjoying at Roller coaster"<<endl;
            }
             while(!Round_wheel.Isempty())
            {
                name=Round_wheel.Dequeue();
                cout<<"Visitor "<<name<<" now enjoying at Round wheel"<<endl;
            }
             while(!Motion_Ride.Isempty())
            {
                name=Motion_Ride.Dequeue();
                cout<<"Visitor "<<name<<" now enjoying at Motion Ride"<<endl;
            }

        }
        else if (x==4)
        {
            cout <<"Program exited successfully "<<endl;
            return 0;
        }
        else{
            cout<<"Invalid Input "<<endl;
        }
    }
}