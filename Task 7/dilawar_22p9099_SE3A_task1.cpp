#include <iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int capacity;
    int length;
    string  *arr;
    public:
    Queue(int capacity)
    {
    this->capacity=capacity;
    rear=-1;
    front=0;
    length=0;
    arr=new string[capacity];

    }
    void Enqueue(string data)
    {
        if(IsFull())
        {
            return ;
        }

       else if(rear==capacity-1)
       {
        rear=0;
       }
       else
       {
        rear++;
       }

       arr[rear]=data;
       length++;
    }
    string Dequeue()
    {
        if(IsEmpty()==true)
        {
            return " ";
        }
        string temp=arr[front];
         if(front==capacity-1)
        {
            front=0;
        }
        else 
        {
            front++;
        }
        
        length--;
        return temp;
    }
    bool IsFull()
    {
        if(length==capacity)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    bool IsEmpty()
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
    string getFront()
    {
        if(IsEmpty())
        {
            return " ";
        }
        else
        {
            return arr[front];
        }
    }
    void Display()
    {
        int index=front;
        for(int i=0;i<length;i++)
        {
             cout<<arr[index]<<endl;
            if(index==capacity-1)
            {
                index=0;
            }
           
            index++;
        }
    }
    ~Queue()
    {
        delete [] arr;
    }

    
};
int main()
{
    int max_patients;
    int x;
    string name;


    cout<<"Enter the number of seats in the waiting area"<<endl;
    cin>>max_patients;
    Queue patients(max_patients);

    while(1)
    {
        cout<<"Please enter an option "<<endl;
        cout<<"1- Enter a patient in waiting queue"<<endl;
        cout<<"2- Send next patient to the doctor  "<<endl;
        cout<<"3- See who is next "<<endl;
        cout<<"4- Display all patients in the queue"<<endl;
        cout<<"5- Exit"<<endl;
        cin>>x;

        if(x==1 )
        {
            if(patients.IsFull())
            {
                cout<<"All seats are already full"<<endl;
            }
            else{
            cout<<"Enter the name of patient "<<endl;
            getline(cin>>ws,name );
            patients.Enqueue(name);
            cout<<"Patient "<<name <<" now waiting in the queue "<<endl;
            }

        }
        else if(x==2)
        {
            name=patients.Dequeue();
            if( name==" ")
            {
                cout<<"No more patients in the queue"<<endl;
            }
            else 
            {
                cout<<"Patient "<<name<<" now with doctor "<<endl;
            }
        }
        else if(x==3)
        {
            
            name=patients.getFront();
            if( name==" ")
            {
                cout<<"No patients in the queue"<<endl;
            }
            else 
            {
                cout<<"Next Patient is "<<name<<endl;
            }
        }
        else if (x==4)
        {
            cout<<"Names of patients in queue are "<<endl;
            patients.Display();
        }
        else if(x==5 )
        {
            cout<<"Program Exited Successfully "<<endl;
            return 0;
        }
        else
        {
           cout<<"Invalid Input "<<endl;
        }


    }

    
}