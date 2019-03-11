//p14.4
%通常定义为非成员    %=通常定义为类成员，因为它会改变对象的状态
++通常定义为类成员，因为他会改变对象的状态   ->必须定义为类成员，否则编译会报错
<<通常定义为非成员 &&通常定义为非成员 ==通常定义为非成员
()通常定义为类成员，否则编译会报错。

//p14.6 14.7 14.8
friend ostream& operator<<(ostream &os,const Sales_data &sd);

//p14.35 p14.36
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ReadString{
	public:
		ReadString(istream &is=cin) : is(is){}
		string operator()()
		{
			string line;
			if(!getline(is,line))
			{
				line=" ";
			}
			return line;
		}
	private:
	    istream& is;
};

int main()
{
	ReadString rs(cin);
	vector<string> vs;
	while(true)
	{
		string line=rs();
		if(!line.empty())
		{
			vs.push_back(line);
		}
		else
		{
			break;
		}
	}
	cout << vs.size() << endl;
	return 0;
}

//p14.38
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Equalen{
	public:
		Equalen(size_t sz) : sz(sz){}
		bool operator()(const string &str)
		{
			return str.size()==sz;
		}
	private:
		size_t sz;
};

int main()
{
	vector<string> vs;
	while(true)
	{
		string line;
		cin >> line;
		if(line.empty())
		{
			break;
		}
		else
		{
			vs.push_back(line);
		}
	}
	for(size_t i=1;i<=10;i++)
	{
		cout << count_if(vs.begin(),vs.end(),Equalen(i)) << " ";
	}
	cout << endl;
	return 0;
}

//p14.43
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;



int main()
{
	int size=3;
	vector<int> vi;
	vi={3,6,9};
	int count=count_if(vi.begin(),vi.end(),bind2nd(modulus<int>(),size));
	if(count==0)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
