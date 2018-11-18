//p6.7
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int GetNum()
{
	static int cnt=0;
	if(cnt==0)
	{
		return cnt++;
	}
	else
	{
		return cnt++;
	}
}

int main()
{
	for(int i=0;i<10;i++)
	{
		cout<<GetNum()<<endl;
	}
	return 0;
}
//p6.8
#ifndef FUNCTION_H
#define FUNCTION_H


int GetNum();
int GetProduct(int n);

#endif
//p6.10
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void changeNum(int *p1,int *p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}

int main()
{
	int a=10;
	int b=20;
	changeNum(&a,&b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
