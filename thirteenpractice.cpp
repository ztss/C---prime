//p13.5
HasPtr::HasPtr(const HasPtr& h) : ps(new string (*h.ps)), i(h.i) {}

//p13.6
当对类对象进行赋值时，会使用拷贝赋值运算符。
通常情况下，合成的拷贝赋值运算符会将右侧对象的非static成员逐个的赋予左侧对象的对应成员，
这些赋值操作由成员类型的拷贝赋值运算符完成。

//13.8
HasPtr& HasPtr::operator=(const HasPtr &h)
{
  auto newps=new string(*h.ps);
  delete ps;//销毁原来的ps
  ps=newps;
  i=h.i;
  return *this;
}

//p13.11
~HasPtr(){delete ps};

//p13.13
#include<memory>
#include<vector>
#include<iostream>
using namespace std;

struct X{
	X()
	{
		cout <<"X()" << endl;
	}

	X(const X&)
	{
		cout << "X(const X&)" << endl;
	}

	X& operator=(const X&)
	{
		cout << "X& operator=(const X&)" << endl;
	}

	~X()
	{
		cout << "~X" << endl;
	}
};

void Fun1(X x);
void Fun2(X &x);


int main()
{
	X x;
	Fun1(x);
	Fun2(x);
	cout << "dongtai fenpei" << endl;
	X *nx=new X;
	delete nx;
	cout << "add it to container" << endl;
	vector<X> vx;
	vx.push_back(x);

	cout << "jianjiechushihuahefuzhi" << endl;
	X y=x;
	y=x;
	return 0;
}

void Fun1(X x)
{
	cout << "Fun1" << endl;
}

void Fun2(X &x)
{
	cout << "Fun2" << endl;
}
