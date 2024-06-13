#include <iostream>
#include <vector>
using namespace std;

class Patient
{
public:
    string name;
    int urgency;

    Patient(string name, int urgency)
    {
        this->name = name;
        this->urgency = urgency;
    }
};

class Heap
{
public:
    vector<Patient> htree;

    int getParent(int child)
    {
        int temp = (child - 1) / 2;
        return temp;
    }

    int getLeft(int parent)
    {
        int temp = (2 * parent) + 1;
        return temp;
    }

    int getRight(int parent)
    {
        int temp = (2 * parent) + 2;
        return temp;
    }

    void swap(Patient *a, Patient *b)
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        if (node == 0)
        {
            return;
        }

        if (htree[node].urgency > htree[getParent(node)].urgency)
        {
            return;
        }

        else if (htree[node].urgency < htree[getParent(node)].urgency)
        {
            swap(&htree[node], &htree[getParent(node)]);
        }

        heapifyUp(getParent(node));
    }

    void heapifyDown(int node)
    {
        if (node > htree.size() / 2)
        {
            return;
        }
        if (htree[node].urgency < htree[getLeft(node)].urgency && htree[node].urgency < htree[getRight(node)].urgency)
        {
            return;
        }
        else if (htree[node].urgency > htree[getLeft(node)].urgency || htree[node].urgency > htree[getRight(node)].urgency)
        {
            if (htree[getLeft(node)].urgency < htree[getRight(node)].urgency)
            {
                swap(&htree[node], &htree[getLeft(node)]);
                heapifyDown(getLeft(node));
            }
            else
            {
                swap(&htree[node], &htree[getRight(node)]);
                heapifyDown(getRight(node));
            }
        }
    }

    void insert(Patient patient)
    {
        htree.push_back(patient);
        heapifyUp(htree.size() - 1);
    }

    void del()
    {
        if (htree.empty())
        {
            cout << "No appointments to delete." << endl;
            return;
        }
            Patient temp=htree[0];
        swap(&htree[0], &htree[htree.size() - 1]);
        htree.pop_back();
        heapifyDown(0);
        cout<<temp.name<<" sent to doctor "<<endl;
    }

    void updateUrgency(string patientName, int newUrgency)
    {
        for (int i = 0; i < htree.size(); i++)
        {
            if (htree[i].name == patientName)
            {
                Patient temp = htree[i];

                htree[i].urgency = newUrgency;
                if (newUrgency < temp.urgency)
                {
                   heapifyUp(i);
                }
                else
                {
                    
                    heapifyDown(i);
                }
                cout<<"Urgency updated "<<endl;
                return;
            }
        }

        cout<<"Patient Not found "<<endl;
    }

    void display()
    {
        if (htree.empty())
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++)
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

int main()
{
    Heap priorityQueue;
    string name;
    int urgency;
    int x;

    while(1)
    {
        cout<<"Please select an option "<<endl;
        cout<<"1- Schedule Appointment"<<endl;
        cout<<"2- Send next patient to doctor "<<endl;
        cout<<"3- Update Urgency"<<endl;
        cout<<"4- View Appointments"<<endl;
        cout<<"5- Exit"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter patient's name "<<endl;
            getline(cin>>ws,name);
            cout<<"Enter urgency "<<endl;
            cin>>urgency;
            Patient p1(name,urgency);
            priorityQueue.insert(p1);
        }
        else if(x==2)
        {
           
            priorityQueue.del();
            priorityQueue.display();
        }
        else if(x==3)
        {
            cout<<"Enter the patient's name to change Urgency "<<endl;
            getline(cin>>ws,name);
            cout<<"Enter new urgency "<<endl;
            cin>>urgency;
            priorityQueue.updateUrgency(name,urgency);

        }
        else if (x==4)
        {
            priorityQueue.display();
        }
        else if(x==5)
        {
            cout<<"Program exited successfully "<<endl;
            return 0;
        }





    }
}