//p8.1
#include<iostream>
#include<stdexcept>
using namespace std;

istream& f(istream& in)
{
	int num;
	while(in>>num,!in.eof())
	{
		if(in.bad())
		{
			throw runtime_error("IO error");
		}
		if(in.fail())
		{
			cerr << "data error,retry!"<<endl;
			in.clear();
			in.ignore(100,'\n');
			continue;
		}
		cout<<num<<endl;
	}
	in.clear();
	cout<<in.rdstate()<<endl;
	return in;
}

int main()
{
	f(cin);
	return 0;
}
