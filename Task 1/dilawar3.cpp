#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
	int month[4][7];
	int* ptr=&month[0][0];
	int num;
	
	//part 1
	srand(time(NULL));
	for(int i=0;i<28;i++)
	{
		num=10+(rand()%30);
		*ptr=num;
		ptr++;
	}
	
	//part2
	cout<<"The Temprature of whole month is "<<endl;
	ptr=&month[0][0];
	for(int i=0;i<28;i++)
	{
		cout<<"Day "<<i+1<<": "<<*ptr<<endl;
		ptr++;
	}
	
	//part3
	
	
	ptr=&month[0][0];
	
	for(int i=0;i<4;i++)
	{
		int hotest=0;
	for(int j=0;j<7;j++)
	{
		if(*ptr>hotest)
		{
			hotest=*ptr;
		}
		ptr++;
	}
		ptr=&month[i][0];
		int k;
	for( k=0;k<7;k++)
	{
		if(*ptr==hotest)
		{
			break;
		}
		ptr++;
	}
	cout<<"The hotest day of week "<<i+1<<" is "<<k+1<<" with temprature of "<< hotest<<" C"<<endl;
}
	
}
