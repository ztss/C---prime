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

//p6.17
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool has_upper(const string &s);
void to_lower(string &s);

int main()
{
	string str="sTrssssss";
	if(has_upper(str))
	{
		cout<<"str has upper character!"<<endl;
	}
	else
	{
		cout<<"yoho"<<endl;
	}
	to_lower(str);
	cout<<str<<endl;
	return 0;
}

bool has_upper(const string &s)
{
	for(auto i:s)
	{
		if(isupper(i))
		{
			return true;
		}
	}
	return false;
}

void to_lower(string &s)
{
	for(auto &i:s)
	{
		i=tolower(i);
	}
}

//p6.19
vector<int>::iterator chage_val(int i,vector<int>::iterator s);

//p6.21
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;

int get_maxnum(const int i,const int *j);

int main()
{
	int i=10;
	int h=100;
	int *j=&h;
	cout<<get_maxnum(i,j)<<endl;
	return 0;
}

int get_maxnum(const int i,const int *j)
{
	int res=i>(*j)?i:*j;
	return res;
}

//p6.22
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;

void change_pointer(int *&p1,int *&p2);

int main()
{
	int i=10,j=5;
	int *p1=&i;
	int *p2=&j;
	cout<<*p1<<" "<<*p2<<endl;
	change_pointer(p1,p2);
	cout<<*p1<<" "<<*p2<<endl;
	return 0;
}

void change_pointer(int *&p1,int *&p2)
{
	int *temp;
	temp=p1;
	p1=p2;
	p2=temp;
}

//p6.25
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc,char *argv[])
{
	for(int i=0;i<argc;i++)
	{
		cout<<argv[i]<<" "<<endl;
	}
	cout<<endl;
	return 0;
} 
