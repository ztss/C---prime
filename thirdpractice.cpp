//practice 3.17:
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void output(vector<string> temp);

int main()
{
	vector<string> strs;
	string str;
	while(cin>>str)
	{
		strs.push_back(str);
	}
	for(auto &i:strs)
	{
		for(auto &j:i)
		{
			j=toupper(j);
		}
	}
	for(auto i:strs)
	{
		cout<<i<<endl;
	}
	return 0;
}

void output(vector<string> temp)
{
	for(decltype(temp.size()) i=0;i<temp.size();i++)
	{
		if(i!=temp.size()-1)
		{
			cout<<temp[i]<<" ";
		}
		else
		{
			cout<<temp[i]<<endl;
		}
	}
}

practice 3.20
可以先将vector对象的值读入，然后利用下标访问即可

//practice 3.22
for(auto iter=txt.begin();!iter->empty&&iter!=txt.end();iter++)
{
  *iter=toupper(*iter);
  cout<<*iter<<endl;
}

//practice 3.23
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<int> res;
	int n=10;
	for(int i=0;i<n;i++)
	{
		res.push_back(i);
	}
	for(auto iter=res.begin();iter!=res.end();iter++)
	{
		*iter=*iter*2;
	}
	for(auto i:res)
	{
		cout<<i<<" "<<endl;
	}
	return 0;
}

3.34.此程序的功能是将p1所指向的位置变为p2所指向的位置。
3.35
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;


int main()
{
int data[10];
for(int i=0;i<10;i++)
{
data[i]=i;
}
int *t1=begin(data);
int *t2=end(data);
while(t1!=t2)
{
*t1=0;
t1++;
}
for(auto i:data)
{
cout<<i<<endl;
}
return 0;
}

3.36
这里比较两个vector是否相等，使用迭代器。

3.38 首先我们必须知道指针的值是指针所指对象的地址值，那么两个指向相加，得到的是两个地址
     值的和，这明显是没有意义的。而两个指向的减法则是有意义的，表示的两个指针所指对象的
     距离。

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
