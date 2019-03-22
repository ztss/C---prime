//p16.2
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
using namespace std;

template<typename T>
bool compare(const T& t1,const T& t2)
{
	if(t1<t2)
	{
		return true;
	}
	return false;
}

int main()
{
	int a=2,b=3;
	string str1="asdddd";
	string str2="ksksidkdkdkd";
	if(compare(str1,str2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}

//p16.4
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<list>
#include<vector>
using namespace std;

template<typename I,typename T>
I Find(I b,I e,const T& t)//返回一个迭代器类型
{
	for(auto i=b;i!=e;i++)
	{
		if(*i==t)
		{
			return i;
		}
	}
}

int main()
{
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	const int f=7;
	cout << *(Find(vi.begin(),vi.end(),f)) << endl;
	cout << "we can find in " << (Find(vi.begin(),vi.end(),f))-vi.begin() << endl;
	return 0;
}


//p16.5 p16.6 p16.7
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<list>
#include<vector>
using namespace std;

template<typename I>
void Print(I b,I e)
{
	for(auto i=b;i!=e;i++)
	{
		cout << *i << endl;
	}
}

template<typename I,typename T>
I Find(I b,I e,const T& t)//返回一个迭代器类型
{
	for(auto i=b;i!=e;i++)
	{
		if(*i==t)
		{
			return i;
		}
	}
}

template<typename T,unsigned N>
void PRint(const T (&a)[N])
{
	for(auto i=begin(a);i!=end(a);i++)//注意这里数组迭代器的用法
	{
		cout << *i << " ";
	}
	cout << endl;
}

template<typename T,size_t N>
const T* my_begin(const T (&a)[N])
{
	return &a[0];
}

template<typename T,size_t N>
const T* my_end(const T (&a)[N])
{
	return &a[0]+N;
}

template<typename T,size_t N>
constexpr int get_size(const T (&a)[N])
{
	return N;
}

int main()
{
	int a[6]={12,13,15,16,17,18};
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	const int f=7;
	cout << *(Find(vi.begin(),vi.end(),f)) << endl;
	cout << "we can find in " << (Find(vi.begin(),vi.end(),f))-vi.begin() << endl;
	Print(vi.begin(),vi.end());
	PRint(a);
	cout << *my_begin(a) << " " << *my_end(a) << endl;
	cout << get_size(a) << endl;
	return 0;
}


//p16.12
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<list>
#include<vector>
using namespace std;

template<typename T> class BlobPtr;
template<typename T> class Blob;
template<typename T>
bool operator==(const Blob<T>&,const Blob<T>&);


template<typename T> class Blob{
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&,const Blob<T>&);
	public:
		typedef T value_type;
		typedef typename vector<T>::size_type size_type;
		Blob();
		Blob(initializer_list<T> il);
		size_type size() const
		{
			return data->size();
		}
		bool empty() const
		{
			return data->empty();
		}
		void push_back(const T &t)
		{
			data->push_back(t);
		}
		void pop_back();
		//元素访问
		T& back();
		T& operator[](size_type i);
	private:
		shared_ptr<vector<T>> data;
		void check(size_type i,const string &msg) const;
};

template<typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()) {}

template<typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

template<typename T>
void Blob<T>::check(size_type i,const string& msg) const
{
	if(i>=data->size())
	{
		throw out_of_range(msg);
	}
}

template<typename T>
T& Blob<T>::back()
{
	check(0,"this is a empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i,"subscipt out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0,"this is a empty Blob");
	data->pop_back();
}

template<typename T> class BlobPtr{
	public:
		BlobPtr() : curr(0) {}
		BlobPtr(Blob<T> &a,size_t sz=0): wptr(a.data),curr(sz) {}
		T& operator*() const
		{
			auto p=check(curr,"deference past end");
			return (*p)[curr];
		}
		BlobPtr& operator++();
		BlobPtr& operator--();
	private:
		shared_ptr<vector<T>> check(size_t,const string&) const;
		weak_ptr<vector<T>> wptr;
		size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{

}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{

}

int main()
{
	Blob<int> squares={0,1,2,3,4,5,6,7,8,9};
	return 0;
}


//p16.19 p16.20
#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include<list>
#include<vector>
using namespace std;

template<typename T>
void Print(const T& t)
{
	for(typename T::size_type i=0;i<t.size();i++)
	{
		cout << t[i] << " ";
	}
	cout << endl;
}

template<typename T>
void PRint(const T& t)
{
	for(auto iter=t.begin();iter!=t.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> squares={0,1,2,3,4,5,6,7,8,9};
	Print(squares);
	PRint(squares);
	return 0;
}
