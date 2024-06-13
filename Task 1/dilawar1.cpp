#include <iostream>
using namespace std;
void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

int main()
{
    int x;
    int y;
    int *ptr1=&x;
    int *ptr2=&y;
    cout<<"Enter value of x"<<endl;
    cin>>x;
    
    cout<<"Enter value of y"<<endl;
    cin>>y;
    
    cout<<"Before Swap:"<<endl;
    cout<<"X: "<<*ptr1<<endl;
    cout<<"Y: "<<*ptr2<<endl;

     swap(ptr1,ptr2);

     cout<<"After Swap:"<<endl;
    cout<<"X: "<<*ptr1<<endl;
    cout<<"Y: "<<*ptr2<<endl;

}
