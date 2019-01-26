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

//
