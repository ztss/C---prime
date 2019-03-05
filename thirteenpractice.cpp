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


//p13.17
#include<memory>
#include<vector>
#include<iostream>
using namespace std;

struct numbered{
	int mysn;
	numbered(): mysn(0) {cout << "moren contruction func" << endl;}
	numbered(const numbered &n)
	{
		cout << "copy construction func" << endl;
		mysn=n.mysn+1;
	}
	numbered& operator=(const numbered &n)
	{
		cout << "copy==func" << endl;
		mysn=n.mysn+1;
		return *this;
	}
};

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);
	return 0;
}


//p13.18 13.19
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Employee{
	public:
		Employee() : No(GetNo++),name("") { cout <<"default construction func" << endl; };
		Employee(const string &str): No(GetNo++),name(str){cout << "construction func with a string" << endl; };
		Employee(const Employee&e)//拷贝构造函数
		{
			No=GetNo++;
			name=e.name;
			cout << "copy construction func" << endl;
		}
		Employee& operator=(const Employee&e)//拷贝赋值函数
		{
			No=GetNo++;
			name=e.name;
			return *this;
			cout << "copy assignment func" << endl;
		}
		const string& Get_Name()
		{
			return name;
		}
		int Get_No()
		{
			return No;
		}
	private:
		static int GetNo;
		int No;
		string name;
};

int Employee::GetNo=0;

void f(Employee &s)
{
	cout << s.Get_Name() << " " << s.Get_No() << endl;
}

int main()
{
	Employee a("a"),b=a,c;
	cout << "hey im here" << endl;
	c=b;
	cout << "do this step" << endl;
	f(a);
	f(b);
	f(c);
	return 0;
}

//p13.22
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class HasPtr{
	public:
		HasPtr(const string &s): a(0),str(new string(s)) {};//默认构造函数
		HasPtr(const HasPtr&h)//拷贝构造函数
		{
			a=h.a;
			str=new string(*h.str);
		}
		HasPtr& operator=(const HasPtr&rhs);//拷贝赋值函数
		~HasPtr()//析构函数
		{
			delete str;
		}
		const string& Get_String()
		{
			return *str;
		}
	private:
		int a;
		string *str;
};

inline HasPtr& HasPtr::operator=(const HasPtr&rhs)
{
	auto newstr=new string(*rhs.str);
	delete str;
	str=newstr;
	a=rhs.a;
	return *this;
}

int main()
{
	HasPtr z("hi zhangtao");
	cout << z.Get_String() << endl;
	HasPtr a(z);
	cout << a.Get_String() << endl;
	HasPtr n=z;
	cout << n.Get_String() << endl;
	return 0;
}


//13.27
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class HasPtr{
	public:
		HasPtr(const string&s) : str(new string(s)),i(0),num(new size_t(1)) {};
		HasPtr(const HasPtr&h) : str(h.str),i(h.i),num(h.num)
		{
			++*num;
		}
		HasPtr& operator=(const HasPtr &rhs);
		const string& operator*();
		size_t Get_No()
		{
			return *num;
		}
		~HasPtr();
	private:
		string *str;
		int i;
		size_t *num;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.num;
	if(--*num==0)
	{
		delete str;
		delete num;
	}
	str=rhs.str;
	num=rhs.num;
	i=rhs.i;
	return *this;
}

const string& HasPtr::operator*()
{
	return *str;
}

HasPtr::~HasPtr()
{
	if(--*num==0)
	{
		delete str;
		delete num;
	}
}

int main()
{
	HasPtr z("hi,i am zhang");
	HasPtr a(z);
	HasPtr n=a;
	cout << *z << " " << z.Get_No() << endl;
	cout << *a << " " << a.Get_No() << endl;
	cout << *n << " " << n.Get_No() << endl;
	return 0;
}


//13.30 13.31
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class HasPtr{
	friend void swap(HasPtr &lhs,HasPtr &rhs);
	public:
		HasPtr(const string &s): a(0),str(new string(s)) {};//默认构造函数
		HasPtr(const HasPtr&h)//拷贝构造函数
		{
			a=h.a;
			str=new string(*h.str);
		}
		HasPtr& operator=(const HasPtr&rhs);//拷贝赋值函数
		HasPtr& operator=(const string &s);
		bool operator<(const HasPtr &rhs) const;//不改变成员变量，所以定义为const。
		~HasPtr()//析构函数
		{
			delete str;
		}
		const string& Get_String()
		{
			return *str;
		}
	private:
		int a;
		string *str;
};

inline HasPtr& HasPtr::operator=(const HasPtr&rhs)
{
	auto newstr=new string(*rhs.str);
	delete str;
	str=newstr;
	a=rhs.a;
	return *this;
}

inline HasPtr& HasPtr::operator=(const string &s)
{
	auto newstr=new string(s);
	delete str;
	str=newstr;
	a=0;
	return *this;
}

inline void swap(HasPtr &lhs,HasPtr &rhs)
{
	//using std::swap;
	swap(lhs.str,rhs.str);
	swap(lhs.a,rhs.a);
}

inline bool HasPtr::operator<(const HasPtr &rhs) const
{
	return *str<*rhs.str;
}

int main()
{
	vector<HasPtr> vh;
	for(int i=9;i>=0;i--)
	{
		vh.push_back(to_string(i));
	}
	for(auto i:vh)
	{
		cout << i.Get_String() << endl;
	}
	sort(vh.begin(),vh.end());
	for(auto i:vh)
	{
		cout << i.Get_String() << endl;
	}
	return 0;
}


//p13.32
默认的swap版本简单的交换两个对象非静态成员，对于类指针的HasPtr来说就是交换了string指针
引用计数指针，和整型值i。这是符合我们的期望的。所以，定义自己的swap版本并会比默认的做的
更好。
