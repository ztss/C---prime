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

//p10.20
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
	auto num=count_if(vs.begin(),vs.end(),[](const string &str)->bool{
	if(str.size()>6) return true; else return false;});
	cout << num << endl;
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

//p10.21
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;

void test_lambda()
{
	int a=5;
	auto f=[a]()mutable->bool{if(a==0) return true; else a--; return false;};//这里也可以使用引用捕获达到同样的目的
	for(int i=0;i<6;i++)
	{
		cout << f() << " " << endl;
	}
	cout << endl;
}

int main()
{
	test_lambda();
	return 0;
}

//p10.22
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
using namespace std;
using namespace std::placeholders;//注意这里

bool greaterThen6(const string & str,int sz);

int main()
{
	vector<string> vs;
	string str;
	while(cin>>str)
	{
		vs.push_back(str);
	}
	auto num=count_if(vs.cbegin(),vs.cend(),bind(greaterThen6,_1,6));
	cout << num << endl;
	return 0;
}

bool greaterThen6(const string & str,int sz)
{
	if(str.size()<=6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//p10.24
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool intGreaterstr(const int &a,const string &str)
{
	if(a>str.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	string str="hello";
	auto p=find_if(vi.cbegin(),vi.cend(),bind(intGreaterstr,_1,str));
	cout << *p << endl;
	return 0;
}
