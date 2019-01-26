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
