//p7.1.2
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person
{
private:
    string name;
	string address;
public:
    string GetName() const
	{
		return name;
	}
	string GetAddress() const
	{
		return address;
	}
};

//p7.1.3
#include<iostream>
#include<string>
#include<vector>
using namespace std;

istream &read(istream &is,Person &item);
ostream &print(ostream &os,const Person &item);

class Person
{
private:
    string name;
	string address;
public:
    string GetName() const
	{
		return name;
	}
	string GetAddress() const
	{
		return address;
	}
};

istream &read(istream &is,Person &item)
{
	is >> item.name >> item.address;
	return is;
}

ostream &print(ostream &os,const Person &item)
{
	os << item.GetAddress() << " " << item.GetName() << endl;
	return os;
}

//p7.10
read函数返回的是istream的引用，所以read函数的返回值仍然可以作为read函数的第一个参数，
这里是用来检验读入data1,data2数据的过程是否是正确的。

//p7.25
可以，一般使用内置类型作为数据成员类型的类都可以使用默认的拷贝和赋值操作，只有含有指针的
数据成员的类一般不适合使用默认的拷贝和赋值操作。

//p7.31
class Y;
class X
{
  Y *y;
};
class Y
{
  X x;
};
