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

//p8.4
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;



int main()
{
	vector<string> str;
	ifstream input("text.txt");
	if(input)
	{
		string line;
		while(getline(input,line))
		{
			str.push_back(line);
		}
		input.close();
	}
	for(auto i:str)
	{
		cout<<i<<endl;
	}
	return 0;
}
