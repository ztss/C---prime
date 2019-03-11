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
