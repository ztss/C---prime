practice3.43
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;


int main()
{
	int arr[3][4];
	int cnt=0;
	for(auto &i:arr)
	{
		for(auto &j:i)
		{
			j=cnt;
			cnt++;
		}
	}
	//cout<<arr[2][1]<<endl;
	for(const auto &o:arr)
	{
		for(auto p:o)
		{
			cout<< p << " ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int (*p)[4]=arr;p!=arr+3;p++)//这里p是一个指向含有4个元素数组的指针
	{
		for(int *q=*p;q!=*p+4;q++)//所以这里应该是*p，*p代表的是一个含有4个元素的数组。
    //所以这里要定义为*q，*p为数组名字，在这里自动的转换为数组首元素的指针。
		{
			cout<<*q<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
