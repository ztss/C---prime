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
