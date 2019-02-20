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
//p8.5
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
		while(input>>line)
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
//p8.13
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

struct People
{
	string name;
	vector<string> phones;
};

string format(const string& s)
{
	return s;
}

bool valid(const string& s)
{
	return true;
}

int main()
{
	ifstream input("text.txt");
	vector<People> human;
	string line, phone;
	while(getline(input,line))
	{
		People temp;
		istringstream record(line);
		record >> temp.name;
		while(record >> phone)
		{
			temp.phones.push_back(phone);
		}
		human.push_back(temp);
	}
	ostringstream os;
	for(const auto& h:human)
	{
		ostringstream badnums,formatted;
		for(const auto& p:h.phones)
		{
			if(!valid(p))
			{
				badnums << " " << p;
			}
			else
			{
				formatted << " " << format(p);
			}
		}
		if(badnums.str().empty())
		{
			os << h.name << " " << formatted.str() << endl;
		}
		else
		{
			cerr << "input error: " << h.name << " invalid number(s) " << badnums.str() << endl;
		}
	}
	cout << os.str() << endl;
	return 0;
}
