15. 面向对象程序设计
15.1 oop：概述
   1.数据抽象，继承，动态绑定。
   2.在函数的运行过程中由实参决定函数的运行版本，这就是动态绑定，或者说运行时绑定。C++
   语言中，当我们使用基类的引用或者指针调用一个虚函数的时候将发生动态绑定。
   3.对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类将这些函数声明为虚
   函数。
15.2 定义基类和派生类
15.2.1 定义基类
   1.我们定义一个类，如下：
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
   基类通常都应该定义一个虚析构函数，即使该函数不执行任何实际操作。
   2.在C++中，基类必须将它的两种成员函数区分开来，一种是基类希望其派生类覆盖的函数，另
   一种是基类希望派生类直接继承而不要改变的函数。前者基类通常定义为虚函数。
   3.任何构造函数之外的非静态函数都可以是虚函数。成员函数如果没有被声明为虚函数，则其解
   析过程发生在编译时而非运行时。
   4.派生类能访问公有成员，而不能访问私有成员。不过基类也可以有protected成员，允许派生
   类访问，但是禁止其他用户访问。
15.2.2 定义派生类
   1.如下，我们定义Quote的派生类。
   class Bulk_quote : public Quote{
   public:
     Bulk_quote() = default;
     Bulk_quote(const string&,double,size_t,double);
     double net_price(size_t) const override;
   private:
     size_t min_qty;
     double discount=0.0;
   };如果一个派生是公有的，则基类的公有成员也是派生类接口的组成部分。
   2.派生类包含自身以及基类的数据成员。
   3.派生类使用基类的构造函数初始化它的基类部分。即每个类控制它自己的成员初始化过程。首
   先初始化基类的部分，然后按照声明的顺序初始化派生类的成员。
   4.加上final可以防止类被继承。如下
   class NoDrived final {};
