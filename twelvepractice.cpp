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
