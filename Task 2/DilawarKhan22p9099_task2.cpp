#include <iostream>
using namespace std;
class ArrayList
{
    char * arr;
    int size;
    int length;
    char* curr;
    string correctname;
    public:
    void tail()
    {
        curr=arr+length-1;
    }
    void Start()
    {
        curr=arr;
    }
    void setCorrectname(string name)
    {
        correctname=name;
    }
    bool confirm()
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]!=correctname[i])
            {
                return false;
            }
        }
        return true;
    }
    ArrayList(int size)
    {
        this->size=size;
        arr=new char [size];
        length=0;
        curr=&arr[0];
    }
    void Insert(char val, int pos)
    {
        if(length==size)
        {
            cout<<"List already Full "<<endl;
            return;
        }
        else if( pos<1 || pos>length+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        else
        {
            tail();
            for(int i=length;i>=pos;i--)
            {
                *(curr+1)=*curr;
                curr--;
            }
            *(curr+1)=val;
            length++;
        }
    }
    void Remove(int pos)
    {
        if(length==0)
        {
            cout<<"list is already Empty"<<endl;
            return;
        }
        else if( pos<1 || pos> length)
        {
            cout<<"Invalid Position "<<endl;
            return;

        }
        else 
        {
            Start();
            if( pos==1 )
            {
                for(int i=1;i<length;i++)
                {
                    *curr=*(curr+1);
                    curr++;
                }
                length--;
            }
            else{

            
            for(int i=1 ;i<pos;i++)
            {
                curr++;
            }
            for(int i=pos;i<length;i++)
            {
                *curr=*(curr+1);
                curr++;
            }
            length--;
            }

        }
    }
    void Print()
    {
        Start();
        for(int i=0;i<length;i++)
        {
            cout<<*curr;
            curr++;
        }
    }
};
int main ()
{
    string name;
    string corrname;
    int size;
    int x;
    char alphabet;
    int pos=0;
    int step=0;
    



    cout<<"Enter the size of string "<<endl;
    cin>>size;
    cout<<"Enter the shuffled string "<<endl;
    cin>>name;
    cout<<"Enter the correct string "<<endl;
    cin>>corrname;

    

    ArrayList l1(size);
    l1.setCorrectname(corrname);

    for(int i=0;i<size;i++)
    {
        char ch=name[i];
        l1.Insert(ch,i+1);
        
    }
    while(1)
    {
        l1.Print();
        cout<<endl;
        if(l1.confirm()==true)
        {
            cout<<"You win "<<endl;
            cout<<"Steps taken "<<step<<endl;
            return 0;
        }

        cout<<"Choose an option "<<endl;
        cout<<"1- Insert "<<endl;
        cout<<"2- Remove "<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter the character you want to insert"<<endl;
            cin>>alphabet;
            cout<<"Enter the position at which you want to insert "<<endl;
            cin>>pos;
            l1.Insert(alphabet,pos);
            step++;
        }
        else if(x==2)
        {
            cout<<"Enter the position you want to remove "<<endl;
            cin>>pos;
            l1.Remove(pos);
            step++;
        }
    }
}
