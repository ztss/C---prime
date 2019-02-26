//p10.3
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	cout << accumulate(vi.cbegin(),vi.cend(),0) << endl;
	return 0;
}

//p10.5
c风格字符串由于没有重载==，所以只有当两个字符串的指针值相同，即地址值相同的时候才会返回
true。而当两个序列指针不同时，就算字符串完全相同，也不相等。

//10.8
因为标准库算法从不直接操作容器，只是操作迭代器，从而间接访问容器。能不能插入或者删除元素
不在于算法，而在于传递给这些算法的迭代器是否有这样的能力。而back_inserter就有这样的能力
back_inserter在头文件<iterator>中。

//p10.9
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;

void elimDups(vector<string> &sentance);

int main()
{
	vector<string> vs;
	string str;
	while(cin>>str)
	{
		vs.push_back(str);
	}
	for(auto vb=vs.cbegin();vb!=vs.cend();vb++)
	{
		cout << *vb << " ";
	}
	cout << endl;
	elimDups(vs);
	for(auto vb=vs.cbegin();vb!=vs.cend();vb++)
	{
		cout << *vb << " ";
	}
	return 0;
}

void elimDups(vector<string> &sentance)
{
	sort(sentance.begin(),sentance.end());
	auto unique_s=unique(sentance.begin(),sentance.end());//
	sentance.erase(unique_s,sentance.end());
}

//p10.11
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;

void elimDups(vector<string> &sentance);
bool isShorter(const string & str1,const string &str2);

int main()
{
	vector<string> vs;
	string str;
	while(cin>>str)
	{
		vs.push_back(str);
	}
	for(auto vb=vs.cbegin();vb!=vs.cend();vb++)
	{
		cout << *vb << " ";
	}
	cout << endl;
	elimDups(vs);
	for(auto vb=vs.cbegin();vb!=vs.cend();vb++)
	{
		cout << *vb << " ";
	}
	cout << endl;
	sort(vs.begin(),vs.end(),isShorter);
	for(const auto &s: vs)
	{
		cout << s << " ";
	}
	cout << endl;
	return 0;
}

void elimDups(vector<string> &sentance)
{
	sort(sentance.begin(),sentance.end());
	auto unique_s=unique(sentance.begin(),sentance.end());
	sentance.erase(unique_s,sentance.end());
}

bool isShorter(const string & str1,const string &str2)
{
	return str1.size()<str2.size();
}

//p10.18
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;

void elimDups(vector<string> &sentance);
bool isShorter(const string & str1,const string &str2);

int main()
{
	vector<string> vs;
	string str;
	while(cin>>str)
	{
		vs.push_back(str);
	}
	for(auto vb=vs.cbegin();vb!=vs.cend();vb++)
	{
		cout << *vb << " ";
	}
	cout << endl;
	elimDups(vs);
	for(auto vb=vs.cbegin();vb!=vs.cend();vb++)
	{
		cout << *vb << " ";
	}
	cout << endl;
	sort(vs.begin(),vs.end(),isShorter);
	for(const auto &s: vs)
	{
		cout << s << " ";
	}
	cout << endl;
	auto p_l=partition(vs.begin(),vs.end(),[](const string &str){return 3<str.size();});
	for(auto vb=vs.begin();vb!=p_l;vb++)
	{
		cout << *vb << " ";
	}
	cout << endl;
	return 0;
}

void elimDups(vector<string> &sentance)
{
	sort(sentance.begin(),sentance.end());
	auto unique_s=unique(sentance.begin(),sentance.end());
	sentance.erase(unique_s,sentance.end());
}

bool isShorter(const string & str1,const string &str2)
{
	return str1.size()<str2.size();
}
