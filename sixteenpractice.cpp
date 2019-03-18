//p16.2
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
using namespace std;

template<typename T>
bool compare(const T& t1,const T& t2)
{
	if(t1<t2)
	{
		return true;
	}
	return false;
}

int main()
{
	int a=2,b=3;
	string str1="asdddd";
	string str2="ksksidkdkdkd";
	if(compare(str1,str2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}

//p16.4
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<list>
#include<vector>
using namespace std;

template<typename I,typename T>
I Find(I b,I e,const T& t)//返回一个迭代器类型
{
	for(auto i=b;i!=e;i++)
	{
		if(*i==t)
		{
			return i;
		}
	}
}

int main()
{
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	const int f=7;
	cout << *(Find(vi.begin(),vi.end(),f)) << endl;
	cout << "we can find in " << (Find(vi.begin(),vi.end(),f))-vi.begin() << endl;
	return 0;
}


//p16.5 p16.6 p16.7
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<list>
#include<vector>
using namespace std;

template<typename I>
void Print(I b,I e)
{
	for(auto i=b;i!=e;i++)
	{
		cout << *i << endl;
	}
}

template<typename I,typename T>
I Find(I b,I e,const T& t)//返回一个迭代器类型
{
	for(auto i=b;i!=e;i++)
	{
		if(*i==t)
		{
			return i;
		}
	}
}

template<typename T,unsigned N>
void PRint(const T (&a)[N])
{
	for(auto i=begin(a);i!=end(a);i++)//注意这里数组迭代器的用法
	{
		cout << *i << " ";
	}
	cout << endl;
}

template<typename T,size_t N>
const T* my_begin(const T (&a)[N])
{
	return &a[0];
}

template<typename T,size_t N>
const T* my_end(const T (&a)[N])
{
	return &a[0]+N;
}

template<typename T,size_t N>
constexpr int get_size(const T (&a)[N])
{
	return N;
}

int main()
{
	int a[6]={12,13,15,16,17,18};
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	const int f=7;
	cout << *(Find(vi.begin(),vi.end(),f)) << endl;
	cout << "we can find in " << (Find(vi.begin(),vi.end(),f))-vi.begin() << endl;
	Print(vi.begin(),vi.end());
	PRint(a);
	cout << *my_begin(a) << " " << *my_end(a) << endl;
	cout << get_size(a) << endl;
	return 0;
}
