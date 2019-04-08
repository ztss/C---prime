19.特殊工具与技术
19.1 控制内存分配
19.1.1 重载new和delete
   1.string *sp=new string("a value");实际执行了三步，第一步，new表达式调用一个名为
   operator new标准库函数。此函数分配一块足够大，原始的，未命名的内存空间以存储特定类型
   的对象。第二步，编译器运行相应的构造函数，并传入初始值。第三步，返回一个指向该对象的
   指针。
   2.与析构函数类型，operator delete也不允许抛出异常。所以必须使用noexcept异常说明符。
   3.当我们将这两个运算符定义为类的成员时，他们是隐式静态的。我们无须声明static，这是因
   为new和delete操作是在对象构造之前和销毁之后。所以这两个成员必须是静态的。而且不能操
   作类的数据成员。
   4.对于operator new函数或者operator new[]函数来说，它的返回类型必须是void*，第一个
   形参的类型必须是size_t。而对于operator delete函数或者operator delete[]函数来说，
   他们的返回类型必须是void，第一个形参的类型必须是void*。
   5.编写 operator new和operator delete的一个简单方式。如下
   void *operator new(size_t size){
     if(void *mem=malloc(size)){
       return mem;
     }
     else
     {
       throw bad_alloc();
     }
   }
   void operator delete(void *mem) noexcept{
     free(mem);
   }
19.1.2 定位new表达式
   1.allocate和deallocate只负责分配或者释放内存空间。
   2.new (place_address) type [size] {braced initializer list}这是一个定位new表达
   式。当只传入一个指针类型的实参的时候，定位new表达式构造对象但是不分配内存。
   3.调用析构函数会销毁对象，但是不会释放内存。而delete可以释放空间。
19.2 运行时类型识别
   1.RTTI,run-time type identification。由两个运算符实现，typeid运算符，用于返回表达
   式的类型。dynamic_cast运算符，用于将基类的指针或引用安全地转化为派生类的指针或引用。
   2.使用RTTI必须慎重，在可能的情况下，最好是定义虚函数而非直接接管类型管理的重任。
19.2.1 dynamic_cast运算符
   1.使用形式如下
   dynamic_cast<type*>(e);
   dynamic_cast<type&>(e);
   dynamic_cast<type&&>(e);
   e的类型必须满足以下任意一个条件，e的类型是目标type的公有派生类，e的类型是目标type的
   公有基类或者e的类型就是type的类型。
   2.如下，有一个bp指针指向base类。而Drrived是base的公有派生类。则
   if(Derived* dp=dynamic_cast<Derived*>(bp))
   {
     //使用dp指向的Derived对象
   }else{
     //使用bp指向的base对象
   }
   3.而对于引用类型的dynamic_cast
   void f(const base &b)
   {
     try{
       const Derived &d=dynamic_cast<Derived&>(b);
       //使用b引用的derived对象
     }catch(bad_cast){
       //处理转化失败的情况
     }
   }
19.2.2 typeid运算符
   1.我们这样使用typeid运算符
   Derived *dp=new Derived;
   Base *bp=dp;//两个指针都指向derived对象
   if(typeid(*bp)==typeid(*dp)){
     //
   }
   //检查运行时类型是否是某种指定的类型
   if(typeid(*bp)==typeid(Derived))
   {

   }
   2.当typeid作用与指针时(而不是指针所指的对象)，返回的结果是该指针的静态编译时类型。
19.2.3 使用RTTI
   1.我们使用在类中具有继承关系的类实现相等运算符来说明如何使用RTTI。如下，先定义类
   class Base{
     friend bool operator==(const Base&,const Base&);
   public:
     //Base的接口成员
   protected:
     virtual bool equal(const Base&) const;
     //Base的数据成员和其他用于实现的成员
   };
   class Derived: public Base{
   public:
   protected:
     bool equal(const Base&) const;

   };
   然后定义相等运算符，先比较两个运算对象的类型是否相同，然后再调用equal函数比较两个运算
   对象
   bool operator==(const Base& lhs,const Base& rhs){
     return typeid(lhs)==typeid(rhs)&&lhs.equal(rhs);
   }
   然后每个继承体系中的每个类都必须定义自己的equal函数。派生类的所有函数做的第一件事就
   是将实参的类型转换为派生类类型
   bool Derived::equal(const Base &rhs) const{
     //我们清楚这两个类型是相同的，所有转换过程不会抛出异常
     auto r=dynamic_cast<const Derived&>(rhs);
     //执行比较两个Derived对象的操作并且返回结果
   }
   而基类的equal函数则不需要转换形参的类型
   bool Base::equal(const Base& rhs) const{
     //执行比较Base对象的操作
   }
19.2.4 type_info类
19.3 枚举类型
   1.C++11新标准引入了限定作用域的枚举类型。
19.4 类成员指针
   1.成员指针是指可以指向类的非静态成员的指针。
19.4.1 数据成员指针
   1.可以这样定义数据成员指针 auto pdata=&screen::contents;screen是一个类。
   2.我们可以这样使用数据成员指针
   screen myscreen, *pscreen=&myscreen;
   auto s=myscreen.*pdata;
   s=pscreen->*pdata;
   3.因为数据成员一般情况是私有的，所以我们通常不能直接获得数据成员的指针。如果一个像
   screen这样的类希望我们可以访问它的contents成员，最好定义一个函数。令其返回的值是指
   向该成员的指针。
   class screen{
   public:
     static const std::string screen::*data(){
       return &screen::contents;
     }
   };
   可以知道data返回的是一个指向screen类的const string成员的指针。
   const string screen::*pdata=screen::data();
   pdata指向的是类的成员而不是实际的数据，要想使用pdata，必须将他绑定到screen类型的对象
   上。
   auto s=myscreen.*pdata;
19.4.2 成员函数指针
   1.我们可以使用auto来推断成员函数指针的类型，如下
   auto pmf=&screen::get_cursor;
   或者如下
   char (screen::*pmf2)(screen::pos,screen::pos) const;
   pmf2=&screen::get;
   2.可以这样使用成员函数指针
   char c2=(myscreen.*pmf2)(0,0);
   3.我们可以将函数指针作为某个函数的返回类型或者形参类型。
19.4.3 将成员函数用作可调用对象
19.5 嵌套类
   1.一个类可以定义在另一个类的内部，前者称为嵌套类或者嵌套类型。
19.6 union:一种节省空间的类
   1.union是一种特殊的类，一个union可以有多个数据成员，但是任意时刻只有一个数据成员可以
   有值。
   2.union的定义
   union token{
     char cval;
     int ival;
     double dval;
   };
19.7 局部类
   1.类可以定义在某个函数的内部。这样的类我们称为局部类。
   2.局部类的所有成员都必须完整的定义在类的内部，所以，局部类的作用与嵌套类相比相差很远。
   3.局部类不能使用函数作用域中的变量
19.8 固有的不可移植的特性
   1.为了支持底层编程，C++定义了一些固有的不可移植的特性。
19.8.1 位域
   1.类可以将其非静态的数据成员定义为位域，每一个位域含有一定数量的二进制位。
19.8.2 volatile限定符
   1.valatile的确切含义与机器有关，只能通过阅读编译器文档来理解。
   2.关键字volatile告诉编译器不应该对这样的对象进行优化。
   3.合成的拷贝给对volatile对象无效。
19.8.3 链接指示：extern "C"
   1.C++使用链接指示指出任意非C++函数所用的语言。要想把C++代码和其他语言编写的代码放在
   一起使用，要求我们必须有权访问该语言的编译器。并且这个编译器与当前的C++编译器是兼容的
   。
