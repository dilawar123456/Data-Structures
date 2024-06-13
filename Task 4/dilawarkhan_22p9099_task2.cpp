#include <iostream>
using namespace std;
class Node
{
public:
    string song;
    Node *next;
    Node(string song)
    {
        this->song = song;
        next = NULL;
    }
};
class PlayList
{
    Node *head;
    int length;

public:
    PlayList()
    {
        head = NULL;
        length = 0;
    }
    void Insert(string str, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position " << endl;
            return;
        }
        else
        {
            Node *curr = head;
            Node *n = new Node(str);
            if (pos == 1)
            {
                if(head==NULL)
                {
                    head=n;
                    head->next=head;
                }
               else{
                    while(curr->next!=head)
                {
                    curr=curr->next;
                } 
                               
                n->next = head;
                head = n;
                curr->next=head;}
            }
            else
            {

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
    void Remove(int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else
        {
            Node *curr = head;
            Node* curr2=head;
            if (pos == 1)
            {
                while(curr->next!=head)
                {
                    curr=curr->next;
                }    

                head = head->next;
                delete curr2;
                curr->next=head;
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
    int  Search(string str)
    {
        Node* curr=head;
        for(int i=0;i<length;i++)
        {
            if(str==curr->song)
            {
             return i+1;   
            }
            curr=curr->next;
        }

        return -1;
    }
    void Update(int pos ,string name)
    {
        Node* curr=head;
        for(int i=1;i<pos;i++)
        {
            curr=curr->next;
        }
        curr->song=name;
    }
    void Print()
    {
        Node* curr=head;
       do
        {
            cout<<curr->song<<endl;
            curr=curr->next;
        }while(curr!=head);
    }
    void PlaySong()
    {
        Node *curr=head;
        int x;
        while(1)
        {
        cout<<"Now Playing \n"<<curr->song<<endl;
        cout<<"Select an option "<<endl;
        cout<<"1- Play Next Song "<<endl;
        cout<<"2- Pause Song "<<endl;
        cin>>x;
        if(x==1)
        {
            curr=curr->next;
        }
        else if( x==2)
        {
            cout<<"Song paused"<<endl;
            return;
        }
        else 
        {
            cout <<"Invalid Input"<<endl;
        }
        
        }

    }
    int getlength()
    {
        return length;
    }
    ~PlayList()
    {
        Node* curr=head;
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
    PlayList l1;
    int choice;
    string name;
    int pos;
    int fav_lvl;
    

    while(1)
    {
        cout<<"PLEASE SELECT AN OPTION "<<endl;
        cout<<"1- Add Song "<<endl;
        cout<<"2- Delete Song"<<endl;
        cout<<"3- Search for a Song"<<endl;
        cout<<"4- Update a Song Name"<<endl;
        cout<<"5- Print PlayList"<<endl;
        cout<<"6- Play Song "<<endl;
        cout<<"7- Exit"<<endl;
        cin>>choice;
        if (choice==1 )
        {
            cout<<"Please enter the Song Name "<<endl;
            getline(cin>>ws,name);
            cout<<"Please select the favourite level "<<endl;
            cout<<"1- Top Favourite "<<endl;
            cout<<"2- Least Favourite "<<endl;
            cout<<"3- Somewhere Between "<<endl;
            cin>>fav_lvl;
            if(fav_lvl==1)
            {   
                l1.Insert(name,1);
                
            }
            else if (fav_lvl==2)
            {
                int temp=l1.getlength()+1;
                l1.Insert(name,temp);
            }
            else if (fav_lvl==3)
            {
                cout<<"Enter the position where you want to insert song "<<endl;
                cin>>pos;
                l1.Insert(name,pos);
            }

        }
        else if (choice==2 )
        {
            cout<<"Enter the position of song you want to Remove "<<endl;
            cin>>pos;
            l1.Remove(pos);

        }
        else if (choice==3 )
        {
            cout<<"Enter the name of song you are searching for"<<endl;
            cin>>name;
            int temp=l1.Search(name);
            if(temp==-1)
            {
                cout<<"Song not found "<<endl;
            }
            else 
            {
                cout<<"The song "<<name<<" was found and it's favourite level is "<<temp<<endl;
            }
        }
        else if (choice==4 )
        {
            cout<<"Enter the position of song you want to update "<<endl;
            cin>>pos;
            cout<<"Enter the updated song "<<endl;
            cin>>name;
            l1.Update(pos,name);

        }
        else if (choice==5 )
        {
            cout<<"Your Song Playlist :-"<<endl;
            l1.Print();
        }
        else if (choice==6 )
        {
            l1.PlaySong();
        }
        else if (choice==7 )
        {
            cout<<"Program Exited Successfully "<<endl;
            return 0;
        }

    }
}
