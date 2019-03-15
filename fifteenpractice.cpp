//p15.5 p15.3 p15.6
//p15.5 p15.3
#ifndef QUOTE_H
#define QUOTE_H
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



class Quote{
   public:
     Quote() = default;
     Quote(const string &book,double sales_price) :
                     bookNo(book),price(sales_price) {}
     string isbn() const {return bookNo;}
     //派生类负责改写并且使用不同的折扣计算算法
     virtual double net_price(size_t n) const{
       return n*price;
     }
     virtual ~Quote() = default;//对析构函数进行动态绑定
   private:
     string bookNo;
   protected:
     double price=0.0; //代表普通状态下不打折的价格
};


class Bulk_quote : public Quote{
   public:
     Bulk_quote() = default;
     Bulk_quote(const string& book,double p,size_t qty,double disc) :
     Quote(book,p),min_qty(qty),discount(disc) {}
     double net_price(size_t) const override;
   private:
     size_t min_qty;
     double discount;
};


double Bulk_quote::net_price(size_t cnt) const
{
	if(cnt>=min_qty)
	{
		return cnt*(1-discount)*price;
	}
	else
	{
		return cnt*price;
	}
}

double print_total(ostream &os,const Quote& item,size_t n)
{
	double ret=item.net_price(n);
	os << item.isbn() << " " << n << endl;
	return ret;
}

#endif


#include <iostream>
#include "Quote.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	size_t n=50,t=60;
	Bulk_quote bitem("123",12,n,0.2);
	double tprice=print_total(std::cout,bitem,t);
	cout << tprice << endl;
	return 0;

}

//p15.11
virtual void debug() const
{
  cout << bookNo << " " << price << endl;
}

void debug() const override
{
  Quote::debug();//bookNo为private，所以在Bulk_quote中不能访问，只能调用基类的函数访问。
  cout << min_qty << " " << discount << endl;
}

//p15.15
//p15.5 p15.3
#ifndef QUOTE_H
#define QUOTE_H
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



class Quote{
   public:
     Quote() = default;
     Quote(const string &book,double sales_price) :
                     bookNo(book),price(sales_price) {}
     string isbn() const {return bookNo;}
     //派生类负责改写并且使用不同的折扣计算算法
     virtual double net_price(size_t n) const{
       return n*price;
     }
     virtual ~Quote() = default;//对析构函数进行动态绑定
     virtual void debug() const
     {
     	cout << bookNo << " " << price << endl;
	 }
   private:
     string bookNo;
   protected:
     double price=0.0; //代表普通状态下不打折的价格
};


class Disc_quote : public Quote{
	public:
     Disc_quote() = default;
     Disc_quote(const string& book,double price,size_t qty,double disc):
     Quote(book,price),quanlity(qty),discount(disc) {}
     double net_price(size_t) const = 0;//纯虚函数
   protected:
     size_t quanlity =0;
     double discount=0;
};

class Bulk_quote : public Disc_quote{
   public:
     Bulk_quote() = default;
     Bulk_quote(const string& book,double p,size_t qty,double disc) :
	 Disc_quote(book,p,qty,disc) {}
     double net_price(size_t) const override;
     void debug() const override
     {
     	Quote::debug();//bookNo为private，所以在Bulk_quote中不能访问，只能调用基类的函数访问。
     	cout << min_qty << " " << discount << endl;
	 }
};


double Bulk_quote::net_price(size_t cnt) const
{
	if(cnt>=quanlity)
	{
		return cnt*(1-discount)*price;
	}
	else
	{
		return cnt*price;
	}
}

double print_total(ostream &os,const Quote& item,size_t n)
{
	double ret=item.net_price(n);
	os << item.isbn() << " " << n << endl;
	return ret;
}



#endif


//p15.26
//p15.5 p15.3
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



class Quote{
   public:
     Quote() = default;
     Quote(const string &book,double sales_price) :
                     bookNo(book),price(sales_price) { cout << "This is Quote construction function" << endl;}
     string isbn() const {return bookNo;}
     //拷贝控制函数
     //拷贝构造函数
	 Quote(const Quote& q);
	 Quote& operator=(const Quote& q);
     //派生类负责改写并且使用不同的折扣计算算法
     virtual double net_price(size_t n) const{
       return n*price;
     }
     virtual ~Quote() = default;//对析构函数进行动态绑定
   private:
     string bookNo;
   protected:
     double price=0.0; //代表普通状态下不打折的价格
};



class Bulk_quote : public Quote{
   public:
     Bulk_quote() = default;
     Bulk_quote(const string& book,double sp,size_t cnt,double disc) :
	 Quote(book,sp),min_qty(cnt),discount(disc){cout << "This is Bulk_quote construction function" << endl;};
     double net_price(size_t cnt) const override
     {
     	if(cnt>=min_qty)
	    {
		    return cnt*(1-discount)*price;
	    }
	    else
	    {
		    return cnt*price;
	    }
	 }
   private:
     size_t min_qty;
     double discount=0.0;
};



double print_total(ostream &os,const Quote& item,size_t n)
{
	double ret=item.net_price(n);
	os << item.isbn() << " " << n << endl;
	return ret;
}

int main()
{
    size_t t=50,n=60;
	Bulk_quote bitem("123",12,t,0.2);
	double tprice=print_total(cout,bitem,n);
	cout << tprice << endl;
	return 0;
}


//p15.29
//p15.5 p15.3
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<memory>
using namespace std;



class Quote{
   public:
     Quote() = default;
     Quote(const string &book,double sales_price) :
                     bookNo(book),price(sales_price) { cout << "This is Quote construction function" << endl;}
     string isbn() const {return bookNo;}
     //拷贝控制函数
     //拷贝构造函数
	 Quote(const Quote& q);
	 Quote& operator=(const Quote& q);
     //派生类负责改写并且使用不同的折扣计算算法
     virtual double net_price(size_t n) const{
       return n*price;
     }
     virtual ~Quote() = default;//对析构函数进行动态绑定
   private:
     string bookNo;
   protected:
     double price=0.0; //代表普通状态下不打折的价格
};



class Bulk_quote : public Quote{
   public:
     Bulk_quote() = default;
     Bulk_quote(const string& book,double sp,size_t cnt,double disc) :
	 Quote(book,sp),min_qty(cnt),discount(disc){cout << "This is Bulk_quote construction function" << endl;};
     double net_price(size_t cnt) const override
     {
     	if(cnt>=min_qty)
	    {
		    return cnt*(1-discount)*price;
	    }
	    else
	    {
		    return cnt*price;
	    }
	 }
   private:
     size_t min_qty;
     double discount=0.0;
};



double print_total(ostream &os,const Quote& item,size_t n)
{
	double ret=item.net_price(n);
	os << item.isbn() << " " << n << endl;
	return ret;
}

int main()
{
    size_t t=50,n=60;
    vector<shared_ptr<Quote>> sv;
    double sum=0;
	for(int i=0;i<10;i++)
	{
		sv.push_back(make_shared<Bulk_quote>("123",12,t,0.2));
	}
	for(auto it=sv.begin();it!=sv.end();it++)
	{
		sum=sum+it->get()->net_price(n);
	}
	cout << sum << endl;
	return 0;
}


//p15.30
//p15.5 p15.3
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<memory>
using namespace std;



class Quote{
   public:
     Quote() = default;
     Quote(const string &book,double sales_price) :
                     bookNo(book),price(sales_price) { cout << "This is Quote construction function" << endl;}
     string isbn() const {return bookNo;}
     virtual Quote* clone() const &
     {
     	return new Quote(*this);
	 }
	 virtual Quote* clone() &&
	 {
	 	return new Quote(std::move(*this));
	 }
     //派生类负责改写并且使用不同的折扣计算算法
     virtual double net_price(size_t n) const{
       return n*price;
     }
     virtual ~Quote() = default;//对析构函数进行动态绑定
   private:
     string bookNo;
   protected:
     double price=0.0; //代表普通状态下不打折的价格
};



class Bulk_quote : public Quote{
   public:
     Bulk_quote() = default;
     Bulk_quote(const string& book,double sp,size_t cnt,double disc) :
	 Quote(book,sp),min_qty(cnt),discount(disc){
	 cout << "This is Bulk_quote construction function" << endl;};
	 Bulk_quote* clone() const &
	 {
	 	return new Bulk_quote(*this);
	 }
	 Bulk_quote* clone() &&
	 {
	 	return new Bulk_quote(std::move(*this));
	 }
     double net_price(size_t cnt) const override
     {
     	if(cnt>=min_qty)
	    {
		    return cnt*(1-discount)*price;
	    }
	    else
	    {
		    return cnt*price;
	    }
	 }
   private:
     size_t min_qty;
     double discount=0.0;
};

class Basket{
	public:
		void add_item(const Quote &sale)
		{
			items.insert(shared_ptr<Quote>(sale.clone()));
		}
		void add_item(Quote &&sale)
		{
			items.insert(shared_ptr<Quote>(std::move(sale).clone()));
		}
		double total_receipt(ostream&) const;
	private:
		static bool compare(const shared_ptr<Quote> &lhs,const shared_ptr<Quote> &rhs)
		{
			return lhs->isbn() < rhs->isbn();
		}
		multiset<shared_ptr<Quote>,decltype(compare)*> items{compare};

};

double Basket::total_receipt(ostream &os) const
{
	double sum=0.0;
	for(auto iter=items.cbegin();iter!=items.cend();iter=items.upper_bound(*iter))
	{
		sum=sum+print_total(os,**iter,items.count(*iter));
	}
	os<<"Total Sale: " << sum << endl;
	return sum;
}

double print_total(ostream &os,const Quote& item,size_t n)
{
	double ret=item.net_price(n);
	os << item.isbn() << " " << n << endl;
	return ret;
}

int main()
{
    size_t t=50,n=60;
    vector<shared_ptr<Quote>> sv;
    double sum=0;
	for(int i=0;i<10;i++)
	{
		sv.push_back(make_shared<Bulk_quote>("123",12,t,0.2));
	}
	for(auto it=sv.begin();it!=sv.end();it++)
	{
		sum=sum+it->get()->net_price(n);
	}
	cout << sum << endl;
	return 0;
}
