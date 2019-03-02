//p12.2
#ifndef STRBLOB_H
#define STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<stdexcept>
using namespace std;

class StrBlob{
   public:
		typedef vector<string>::size_type size_type;
		StrBlob();
		StrBlob(initializer_list<string> il);
		size_type size() const
		{
			return data->size();
		}
		bool empty() const
		{
			return data->empty();
		}
		void push_back(const string &str)
		{
			data->push_back(str);
		}
		//元素访问
		void pop_back();
		string& front();
		string& back();
		const string& front() const;
		const string& back() const;
   private:
		 shared_ptr<vector<string>> data;
		 void check(size_type i,const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const
{
	if(i>=data->size())
	{
		throw out_of_range(msg);
	}
}

string& StrBlob::front()
{
	check(0,"front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const
{
	check(0,"front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

const string& StrBlob::back() const
{
	check(0,"back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

#endif

//此为main函数，测试StrBlob类
#include <iostream>
#include "STRBLOB.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	StrBlob b1;
	{
		StrBlob b2={"a","an","the"};
		b1=b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	const StrBlob b3=b1;
	cout << b3.front() << " " << b3.back() << endl;
	return 0;
}

//p12.7
#include<memory>
#include<vector>
#include<iostream>
using namespace std;

shared_ptr<vector<int>> GetVec()
{
	return make_shared<vector<int>>();
}

void ReadVec(shared_ptr<vector<int>> vi)
{
	int n;
	while(cin>>n)
	{
		vi->push_back(n);
	}
}

void PrintVec(const shared_ptr<vector<int>> vi)
{
	for(auto i:*vi)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	shared_ptr<vector<int>> vi=GetVec();
	ReadVec(vi);
	PrintVec(vi);
	return 0;
}

//p12.12
这个练习题很重要

//p12.19
#ifndef STRBLOB_H
#define STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<stdexcept>
using namespace std;

//提前声明，作为StrBlob的友元类
class StrBlobPtr;

class StrBlob{
	friend class StrBlobPtr;
   public:
		typedef vector<string>::size_type size_type;
		StrBlob();
		StrBlob(initializer_list<string> il);
		size_type size() const
		{
			return data->size();
		}
		bool empty() const
		{
			return data->empty();
		}
		void push_back(const string &str)
		{
			data->push_back(str);
		}
		//元素访问
		void pop_back();
		string& front();
		string& back();
		const string& front() const;
		const string& back() const;

		//提供给StrBlobPtr的接口
		StrBlobPtr begin();
		StrBlobPtr end();
   private:
		 shared_ptr<vector<string>> data;
		 void check(size_type i,const string &msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}
inline void StrBlob::check(size_type i, const string &msg) const
{
	if(i>=data->size())
	{
		throw out_of_range(msg);
	}
}

inline string& StrBlob::front()
{
	check(0,"front on empty StrBlob");
	return data->front();
}

inline const string& StrBlob::front() const
{
	check(0,"front on empty StrBlob");
	return data->front();
}

inline string& StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

inline const string& StrBlob::back() const
{
	check(0,"back on empty StrBlob");
	return data->back();
}

inline void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

class StrBlobPtr{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
	public:
		StrBlobPtr(): curr(0) {}
		StrBlobPtr(StrBlob &a,size_t sz=0): wptr(a.data),curr(sz) {}
		string& deref() const;
		StrBlobPtr& incr();
		StrBlobPtr& decr();
	private:
		shared_ptr<vector<string>> check(size_t,const string &msg) const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string &msg) const
{
	auto ret=wptr.lock();
	if(!ret)
	{
		throw runtime_error("unbound StrBlobPtr");
	}
	if(i>=ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}

inline string& StrBlobPtr::deref() const
{
	auto p=check(curr,"dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr& StrBlobPtr::decr()
{
	--curr;
	check(-1,"decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
	auto ret=StrBlobPtr(*this,data->size());
	return ret;
}

inline bool eq(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
	auto l=lhs.wptr.lock();
	auto r=rhs.wptr.lock();
	if(l==r)
	{
		return (!r||lhs.curr==rhs.curr);
	}
	else
	{
		return false;
	}
}


inline bool neq(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
	return !eq(lhs,rhs);
}



#endif

//p12.22
为StrBlobPtr类设计接受const StrBlob对象的构造函数。然后为StrBlob定义可以操作const对象
的begin和end。

//12.27
#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<vector>
#include<string>
#include<map>
#include<set>
#include<memory>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class QueryResult;

class TextQuery{
	friend class QueryResult;
	//将字符串转变为标准字符串，即忽略标点符号，将大写改为小写，但是不应该更改原来文本中的字符串
	friend string checkstr(const string &str);
	using line_no=vector<string>::size_type;
	public:
		TextQuery(ifstream &text);
		QueryResult query(const string &str) const;//这里可以去掉str const的成员函数不允许修改类的数据成员
	private:
		shared_ptr<vector<string>> file;
		map<string,shared_ptr<set<line_no>>> wm;

};

TextQuery::TextQuery(ifstream &text): file(new vector<string>)
{
	string line;
	while(getline(text,line))
	{
		file->push_back(text);
		int n=file->size()-1;
		istringstream lt(line);
		string word;
		while(lt>>word)
		{
			auto &lines=wm[word];//lines是一个shared_ptr
			if(!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines.insert(n);
		}
	}
}

inline string checkstr(const string &str)
{
	string s;
	for(auto i:str)
	{
		if(!ispunct(i))
		{
			s=s+tolower(i);
		}
	}
	return s;
}

QueryResult TextQuery::query(const string &str) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc=wm.find(str);
	if(loc==wm.end())
	{
		return QueryResult(str,nodata,file);
	}
	else
	{
		return QueryResult(str,loc->second,file);
	}
}

class QueryResult{
	friend ostream& print(ostream&, const QueryResult&);
	public:
		QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f):
		word(s),lines(p),file(f){};
	private:
		string word;//保存查询单词
		shared_ptr<set<line_no>> lines;//出现的行号
		shared_ptr<vector<string>> file;
};

ostream& print(osream &os,const QueryResult &qr)
{
	os << qr.word << " occurs " << qr.lines->size() << " " 
	<< make_plural(qr.lines->size(),"time","s") << endl;//判断出现几次决定使用times或者time
	for(auto num:*qr.lines)
	{
		os << "\t(line " << num+1 << ")"
		<< *(qr.file->begin()+num) << endl;//得到第几行的数据
	}
	return os;
}


#endif
