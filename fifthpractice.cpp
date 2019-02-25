p5.14
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str;
	string res;
	int cnt=0;
	int ans=1;
	string temp;
	int ansc=0;
	while(cin>>str)
	{
		if(cnt==0)
		{
			temp=str;
		}
		else
		{
			if(temp==str)
			{
				ans++;
			}
			else
			{
				ans=1;
				temp=str;
			}
		}
		if(ansc<ans)
		{
			ansc=ans;
		}
		cnt++;
	}
	if(ansc!=1)
	{
		cout<<ansc<<endl;
	}
	else
	{
		cout<<"No string duplicated!"<<endl;
	}
    return 0;
}
