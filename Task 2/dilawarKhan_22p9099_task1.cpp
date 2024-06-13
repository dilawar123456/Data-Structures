#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    char arr[3][3];
    char *player = &arr[1][1];
    char *curr = &arr[0][0];
    int num;
    int x;
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
    {
        num = rand() % 2;
        if (num == 0)
        {
            *curr = 'X';
        }
        else if (num == 1)
        {
            *curr = '-';
        }
        curr++;
    }
    *player = 'O';

    cout << "Current Position: " << *player << endl;
    cout << "Choose a move , you are standing at the middle of the grid" << endl;
    cout << "1- Top  " << endl;
    cout << "2- Bottom" << endl;
    cout << "3- Left " << endl;
    cout << "4- Right" << endl;
    cin >> x;
    if (x == 1)
    {
        player = &arr[0][0]+1;
    }
    else if (x == 2)
    {
        player = &arr[0][0]+7;
    }
    else if (x == 3)
    {
        player--;
    }
    else if (x == 4)
    {
        player++;
    }

    cout<<"Moved at "<<*player<<endl<<endl;
    if(*player=='-')
    {
        cout<<"Safe Place You won "<<endl;
    }
    else if (*player=='X')
    {
        cout<<"You lost, Collided"<<endl;
    }
    curr=&arr[0][0];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*curr<<"\t";
            curr++;
        }
        cout<<endl;
    }

    
}