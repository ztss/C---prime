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
