14.重载运算与类型转换
14.1 基本概念
   1.当一个重载的运算符是成员函数时，this绑定到左侧运算对象。成员运算符函数的(显式)参数
   数量比运算对象的数量少一个。
14.2 输入和输出运算符
14.2.1 重载输出运算符<<
   1.输出运算符的第一个形参是非常量ostream对象的引用。第二个形参是常量的引用，是我们想
   要打印的类型。返回ostream的引用。
   2.输出运算符应该负责打印对象的内容而不是控制格式，输入输出运算符必须是非成员函数。而
   又因为IO运算符通常需要读写类的非公有数据成员，所以一般声明为友元。
14.2.2 重载输入运算符>>
   1.输入运算符的第一个形参是运算符将要读取的流的引用，第二个形参是将要读入到的非常量对
   象的引用。会返回一个给定流的引用。如下
   istream& operator>>(istream &is,Sales_data &item)
   {
     double price;
     is >> item.bookNo >> item.units_sold >> price;
     if(is)
     {
       item.revenue=item.units_sold*price;
     }
     else
     {
       item=Sales_data();
     }
     return is;
   }
14.3 算术和关系运算符
   1.通常我们把算术运算符和关系运算符定义为非成员函数。形参通常是常量的引用。
14.3.1 相等运算符
14.3.2 关系运算符
14.4 赋值运算符
   1.赋值运算符必须定义为类的成员，复合赋值运算符通常情况下也应该这样做。都返回左侧运算
   对象的引用。
14.5 下标运算符
   1.下标运算符必须是成员函数。
   2.如果一个类包含下标运算符，那他通常会定义两个版本，一个返回普通引用，一个返回常量引
   用。如下
   class StrVec{
   public:
     string& operator[](size_t n)
     {
       return element[n];
     }
     const string& operator[](size_t n) const
     {
       return element[n];
     }
   private:
     string *element;
   };
14.6 递增和递减运算符
   1.递增和递减运算符通常定义为成员函数，而且应该同时定义前置版本和后置版本。
   2.如下
   class StrBlobPtr{
   public:
     StrBlobPtr& operator++();
     StrBlobPtr& operator--();
     StrBlobPtr operator++(int);//这两个为后置运算符
     StrBlobPtr operator--(int);
   };其中后置版本应该返回对象的原值，而不是引用。但是需要移动指针。
14.7 成员访问运算符
   1.在迭代器类和智能指针类中需要用到解引用*运算符和箭头->运算符。如下。
   class StrBlobPtr{
   public:
     string& operator*() const
     {
       auto p=check(curr,"dereference past end");
       return (*p)[curr];
     }
     string* operator->() const
     {
       return & this->operator*();
     }
   };
   2.重载的箭头运算符必须返回类的指针或者自定义了箭头运算符的某个类的对象。
14.8 函数调用运算符
   1.函数调用运算符必须是成员函数。自定义了函数调用运算符的类称为函数对象。如下
   class PrintString{
   public:
     PrintString(ostream& o=cout,char c=' '): os(o),sep(c){}
     void operator()(const string& str) const
     {
       os << str <<sep;
     }
   private:
     ostream& os;
     char sep;
   };
   我们可以这样使用
   PrintString ps;
   ps(s);//在cout中打印s,后面跟一个空格。
   函数对象通常作为泛型算法的实参。如
   for_each(vs.begin(),vs.end(),PrintString(cerr,'\n'));
14.8.1 lambda是函数对象
   1.当lambda表达式通过引用捕获变量的时候，编译器可以直接使用该引用而无须在lambda产生的
   类中将其存储为数据成员。而通过值捕获的变量，这种lambda产生的类建立相应的数据成员以及
   构造函数。
14.8.2 标准库定义的函数对象
   1.在functional头文件中定义了一组函数对象。
14.8.3 可调用对象与function
   1.map<string,int(*)(int,int)> binops;这个表达式构建从运算符到函数指针的映射关系，
   其中函数接受两个int，返回一个int。其中int(*)(int,int)可以用function<int(int,int)>
   代替。function这个类在functional头文件中。
14.9 重载，类型转换与运算符
14.9.1 类型转换运算符
   1.类型转换运算符是类的一种特殊成员函数，负责将一个类类型的值转换为其他类型。一般如下
   所示
   operator type() const;类型转换运算符没有显式的返回类型，也没有形参，必须定义为类的
   成员函数。不能改变转换对象的内容，定义为const。
14.9.2 避免有二义性的类型转换
   1.除了显式的向bool类型的转换外，我们应该尽量避免定义类型转换函数并且尽可能地限制那些
   ‘显然正确’的非显式构造函数。
14.9.3 函数匹配与重载运算符
   1.如果我们对同一个类提供了转换目标是算术类型的类型转换，也提供了重载的运算符，则会遇
   到重载运算符与内置运算符的二义性问题。
