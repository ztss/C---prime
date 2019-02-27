//p11.2
set为集合类型。当需要保存特定的值的集合，即通常是满足或者不满足某种要求的集合。用set最
为方便

//p11.3 && p11.4
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
#include<map>
#include<set>
using namespace std;
using namespace std::placeholders;

string& transfor(string &s);

int main()
{
	map<string,size_t> word_counts;
	set<string> exclude={"the","a","an","The","But","but","as","As"};
	string str;
	while(cin>>str)
	{
		transfor(str);
		if(exclude.find(str)==exclude.end())
		{
			word_counts[str]++;
		}
	}
	for(const auto &m:word_counts)
	{
		cout << m.first << " " << m.second << endl;
	}
	return 0;
}

string& transfor(string &s)
{
	for(int p=0;p<s.size();p++)
	{
		if(s[p]>='A'&&s[p]<='Z')
		{
			s[p]=s[p]-('A'-'a');
		}
		else if(s[p]==','||s[p]=='.')
		{
			s.erase(p,1);
		}
	}
	return s;
}

//p11.7
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
#include<map>
#include<set>
using namespace std;
using namespace std::placeholders;

void add_family(map<string,vector<string>> &family,const string &str)
{
	if(family.find(str)==family.end())
	{
		family[str]=vector<string>();//建立一个空vector
	}
}

void add_child(map<string,vector<string>> &family,const string &str1,const string &str2)
{
	family[str1].push_back(str2);
}

int main()
{
	map<string,vector<string>> family;
	add_family(family,"zhang");
	add_child(family,"zhang","qiang");
	add_child(family,"liu","ming");
	cout << family.size() << endl;
	return 0;
}
