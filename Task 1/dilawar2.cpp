#include <iostream>
using namespace std;
void palindrome(string str)
{
	int size=str.length();
	int check=0;
	char *start=&str[0];
	char* end=&str[size-1];
	for(int i=0;i<(size/2);i++)
	{
		if(*start!=*end)
		{
			check=1;
		}
		start++;
		end--;
	}
	if(check==0)
	{
		cout<<"The string is palindrome "<<endl;
	}
	else if( check==1)
	{
		cout<<"The string is not palindrome "<<endl;
	}
}
 int frequency(string str,char ch)
 {
 	int size=str.length();
 	int count=0;
 	char* ptr=&str[0];
 	for(int i=0;i<size;i++)
 	{
 		if(ch==*ptr)
 		{
 			count++;
		 }
		 ptr++;
 		
	 }
	 
	 return count;
 }

int main()
{
	string str;
	int x;
	char ch;
	cout<<"enter the string without spaces "<<endl;
	cin>>str;
	while(1)
	{
		cout<<"PLEASE SELECT AN OPTION "<<endl;
		cout<<"1- Check if the string is palindrome "<<endl;
		cout<<"2- count frequency of certain character "<<endl;
		cout<<"3- Exit "<<endl;
		cin>>x;
		if(x==1)
		{
			palindrome(str);
		}
		else if(x==2)
		{
			cout<<"Enter the character to check it's frequency "<<endl;
			cin>>ch;
			cout<<"The frequency of '"<<ch<<"' is ";
			cout<<frequency(str,ch)<<endl;
		}
		else if (x==3)
		{
			cout<<"Program exited successfully "<<endl;
			return 0;
		}
	}
}
