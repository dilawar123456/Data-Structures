#include <iostream>
using namespace std;
class Employee
{
    int ID;
    string name;
    string position;
    string department;
    string contact;
    double salary;

public:
    Employee(int ID = 0, string name = "", string position = "", string department = "", string contact = "", double salary = 0)
    {
        setID(ID);
        setName(name);
        setPosition(position);
        setDepartment(department);
        setContact(contact);
        setSalary(salary);
    }
    void setID(int ID)
    {
        this->ID = ID;
    }
    int getID()
    {
        return ID;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setPosition(string position)
    {
        this->position = position;
    }
    void setDepartment(string department)
    {
        this->department = department;
    }
    void setContact(string contact)
    {
        this->contact = contact;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }

    void Display()
    {
        cout << "ID : " << ID << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Positon : " << position << endl;
        cout << "Contact : " << contact << endl;
        cout << "Salary : " << salary << endl;
    }
};
class Node
{
public:
    Employee data;
    Node *left;
    Node *right;
    int height;
    Node(Employee data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 0;
    }
};
class ManagementTree
{
public:
    Node *root;
    ManagementTree()
    {
        root=NULL;
    }
    int Height(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            return root->height;
        }
    }
    int Max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int getBalance(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return Height(root->left) - Height(root->right);
        }
    }
    Node *RotateLeft(Node *root)
    {
        Node *x = root->right;
        Node *temp = x->left;
        x->left = root;
        root->right = temp;

        x->height = 1 + Max(Height(root->left), Height(root->right));
        root->height = 1 + Max(Height(root->left), Height(root->right));

        return x;
    }
    Node *RotateRight(Node *root)
    {
        Node *x = root->left;
        Node *temp = x->right;
        x->right = root;
        root->left = temp;

        x->height = 1 + Max(Height(root->left), Height(root->right));
        root->height = 1 + Max(Height(root->left), Height(root->right));

        return x;
    }
    Node *Insert(Node *root, Employee e1)
    {
        if (root == NULL)
        {
            return new Node(e1);
        }
        else if (e1.getID() == root->data.getID())
        {
            cout << "Employe already present with same ID " << endl;
            return root;
        }
        else if (e1.getID() < root->data.getID())
        {
            root->left = Insert(root->left, e1);
        }
        else if (e1.getID() > root->data.getID())
        {
            root->right = Insert(root->right, e1);
        }
        root->height = 1 + Max(Height(root->left), Height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && e1.getID() < root->data.getID())
        {
            return RotateRight(root);
        }
        else if (balance > 1 && e1.getID() > root->data.getID())
        {
            root->left = RotateLeft(root->left);
            return root->right = RotateRight(root);
        }
        else if (balance < -1 && e1.getID() > root->data.getID())
        {
            return RotateLeft(root);
        }
        else if (balance < -1 && e1.getID() < root->data.getID())
        {
            root->right = RotateRight(root->right);
            return RotateLeft(root);
        }

        return root;
    }
    Node *Search(Node *root, int ID)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->data.getID() == ID)
        {
            return root;
        }
        else if (ID > root->data.getID())
        {
            Search(root->right, ID);
        }
        else if (ID < root->data.getID())
        {
            Search(root->left, ID);
        }
    }
    void Modify(Node *root, int ID)
    {
        Node *temp = Search(root, ID);
        if (temp == NULL)
        {
            cout << "Employee Not found :(" << endl;
            return;
        }
        else
        {
            int x;
            cout << "Which information you want to change?" << endl;
            cout << "1- Name" << endl;
            cout << "2- Position" << endl;
            cout << "3- Department" << endl;
            cout << "4- Contact" << endl;
            cout << "5- Salary" << endl;
            cin >> x;
            if (x == 1)
            {
                string name;
                cout << "Enter new name " << endl;
                getline(cin >> ws, name);
                temp->data.setName(name);
            }
            else if (x == 2)
            {
                string pos;
                cout << "Enter new position of employee " << endl;
                getline(cin >> ws, pos);
                temp->data.setPosition(pos);
            }
            else if (x == 3)
            {
                string Department;
                cout << "Enter the new Department " << endl;
                getline(cin >> ws, Department);
                temp->data.setDepartment(Department);
            }
            else if (x == 4)
            {
                string contact;
                cout << "Enter the new Contact " << endl;
                cin >> contact;
                temp->data.setContact(contact);
            }
            else if (x == 5)
            {
                double salary;
                cout << "Enter the new salary " << endl;
                cin >> salary;
                temp->data.setSalary(salary);
            }
        }
    }
    Node *Successor(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL)
        {
            return root;
        }
        else
        {
            return Successor(root->left);
        }
    }
    Node *Remove(Node *root, int ID)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (ID < root->data.getID())
        {
            root->left = Remove(root->left, ID);
        }
        else if (ID > root->data.getID())
        {
            root->right = Remove(root->right, ID);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
                temp = NULL;
                return root;
            }
            else if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
                temp = NULL;
                return root;
            }
            else
            {
                Node *temp = Successor(root->right);
                root->data = temp->data;
                root->right = Remove(root->right, temp->data.getID());
                 root->height = 1 + Max(Height(root->left), Height(root->right));
            }

           

            int balance = getBalance(root);

            if (balance > 1 && ID < root->data.getID())
            {
                return RotateRight(root);
            }
            else if (balance > 1 && ID > root->data.getID())
            {
                root->left = RotateLeft(root->left);
                return root->right = RotateRight(root);
            }
            else if (balance < -1 && ID > root->data.getID())
            {
                return RotateLeft(root);
            }
            else if (balance < -1 && ID < root->data.getID())
            {
                root->right = RotateRight(root->right);
                return RotateLeft(root);
            }

            return root;
        }
    }
    //THIS FUNCTION IS NOT IMPLEMENTED BY ME
    void printOrganizationalChart(Node* head, int space) {
        if (head == NULL)
            return;

        // Increase distance between levels
        space += 5;

        // Process right child first
        printOrganizationalChart(head->right, space);

        // Print current employee info with proper spacing
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << "| ID: " << head->data.getID() << " - " << head->data.getName() << ")";

        // Process left child
        printOrganizationalChart(head->left, space);
    }
   
};

int main()
{
    ManagementTree t1;
    int choice;
    int ID;
    string name;
    string position;
    string department;
    string contact;
    double salary;

    while (1)
    {
        cout << "Please select an option " << endl;
        cout << "1-Add Employee  " << endl;
        cout << "2- Search for Employee " << endl;
        cout << "3- Generate organizational chart " << endl;
        cout << "4- Modify Employee Information" << endl;
        cout << "5- Remove Employee " << endl;
        cout << "6- Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Employee's ID " << endl;
            cin >> ID;
            cout << "Enter Employee's Name " << endl;
            getline(cin >> ws, name);
            cout << "Enter Employee's Department " << endl;
            getline(cin >> ws, department);
            cout << "Enter Employee's Positon " << endl;
            getline(cin >> ws, position);
            cout << "Enter Employee's Contact number " << endl;
            cin >> contact;
            cout << "Enter Employee's Salary " << endl;
            cin >> salary;

            Employee e1(ID, name, position, department, contact, salary);
            t1.root = t1.Insert(t1.root, e1);
        }
        else if (choice == 2)
        {
            cout << "Enter the ID of Employee  to search " << endl;
            cin >> ID;
            Node *temp = t1.Search(t1.root, ID);
            if (temp == NULL)
            {
                cout << "Employee not found :(" << endl;
            }
            else
            {
                cout << "Employee Found " << endl;
                cout << "Employee's Details:-" << endl;
                temp->data.Display();
            }
        }
        else if (choice == 3)
        {
            t1.printOrganizationalChart(t1.root,0);
            cout<<endl;
        }
        else if (choice == 4)
        {
            cout << "Enter the ID of Employee to Modify " << endl;
            cin >> ID;
            t1.Modify(t1.root, ID);
        }
        else if (choice == 5)
        {
            cout << "Enter the ID of Employee to Remove " << endl;
            cin >> ID;
            t1.Remove(t1.root, ID);
        }
        else if (choice == 6)
        {
            cout << "Program exited Successfully " << endl;
            return 0;
        }
    }
}