13. 拷贝控制
   1.定义一个类的时候，我们显式或者隐式的指定此类型的对象拷贝，移动，赋值和销毁时做什么。
   类通过定义这几种特殊的成员函数控制这些操作。包括拷贝赋值运算符，拷贝构造函数，移动构
   造函数，移动赋值运算符和析构函数。我们称这些操作为拷贝控制操作。
13.1 拷贝，赋值与销毁
13.1.1 拷贝构造函数
   1.如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造
   函数为拷贝构造函数。如下
   class Foo{
   public:
     Foo();//默认构造函数
     Foo(const Foo&);//拷贝构造函数
   };拷贝构造函数能够被隐式的使用，所以不应该是explicit的。
   2.拷贝初始化是依靠拷贝构造函数或者移动构造函数来完成的。一般会使用等于号。还有以下情
   况也会发生拷贝初始化：
   将一个对象作为实参传递给一个非引用类型的形参。
   从一个返回类型为非引用类型的函数返回一个对象
   用花括号列表初始化一个数组中的元素或者一个聚合类中的成员。
13.1.2 拷贝赋值运算符
   1.重载赋值运算符，如下
   class Foo{
   public:
     Foo& operator=(const Foo&);
   };
   2.如果一个类未定义自己的拷贝赋值运算符，编译器会生成一个合成拷贝赋值运算符。
13.1.3 析构函数
   1.析构函数执行与构造函数相反的操作，构造函数初始化对象的非static成员，还可能做一些其
   他的工作。析构函数释放对象使用的资源，并且销毁对象的非static数据成员。如下：
   class Foo{
   public:
     ~Foo();//析构函数
   };对于一个给定的类，只能有唯一的一个析构函数。
   2.在一个对象被销毁的时候，就会自动调用其析构函数
   变量在离开其作用域时被销毁
   当一个对象被销毁的时候，其成员被销毁
   容器被销毁，其元素被销毁
   对于动态分配的对象，当对指向它的指针应用delete运算符时被销毁
   对于临时对象，当创建它的完整表达式结束的时候被销毁
   3.当一个类未定义自己的析构函数时，编译器会为它定义一个合成析构函数。合成析构函数一般
   函数体是空的。
13.1.4 三/五法则
   1.如果一个类需要自定义析构函数，几乎可以肯定它也需要自定义拷贝赋值运算符和拷贝构造函
   数。
   2.如果一个类需要一个拷贝构造函数，几乎可以肯定也需要一个拷贝赋值运算符，反之亦然。
13.1.5 使用=default
   1.通过将拷贝控制成员定义为=default来显式的要求编译器生成合成的版本。
   class Sales_data{
   public:
     Sales_data() = default;
     Sales_data(const Sales_data &) = default;
     Sales_data& operator=(const Sales_data &);
     ~Sales_data() =default;
   };
   Sales_data& Sales_data::operator=(const Sales_data &) = default;
   在类里面使用此用法，函数即为内联函数。
13.1.6 阻止拷贝
   1.我们可以通过将拷贝构造函数和拷贝赋值运算符定义为删除的函数来阻止拷贝。如下：
   struct NoCopy{
     NoCopy() = default;
     NoCopy(const NoCopy&) = delete;
     NoCopy &operator=(const NoCopy&) = delete;
     ~NoCopy() = default;
   };
   2.析构函数不能定义为删除的函数。
13.2 拷贝控制和资源管理
   1.通常，管理类外资源的类必须定义拷贝控制成员。即需要析构函数释放对象所分配的资源。
13.2.1 行为像值的类
   1.为了提供类值的行为，对于类管理的资源，每个对象都应该拥有一份自己的拷贝。所以需要
   定义一个拷贝构造函数，完成string的拷贝，而不是拷贝指针
   定义一个析构函数来释放string
   定义一个拷贝赋值运算符来释放对象当前的string。并且从右侧运算对象拷贝string
   2.编写赋值运算符的时候，必须记住
   如果将一个对象赋予它自身，赋值运算符必须能正确工作
   大多数赋值运算符组合了析构函数和拷贝构造函数的工作，即当编写一个赋值运算符的时候，一
   个好的模式是先将右侧对象拷贝到一个局部临时对象中。当拷贝完成后，销毁左侧运算符的现有
   成员。最后将数据从临时对象拷贝到左侧运算对象的成员中。
13.2.2 定义行为像指针的类
   1.对于行为像指针的类，我们也需要定义拷贝构造函数和拷贝赋值运算符，来拷贝指针本身而不
   是它指向的string。也需要析构函数来释放string参数的构造函数分配的内存。但是只有当最
   后一个指向string的HasPtr销毁的时候，才可以释放string。我们可以使用shared_ptr。也可
   以使用引用计数。
   2.还有一个问题就是在哪里存放引用计数。计数器不能直接作为HasPtr对象的成员。我们可以将
   计数器保存在动态内存中。
13.3 交换操作
   1.对于需要使用重拍元素顺序的算法的类，交换操作是很重要的。
13.4 拷贝控制实例
   1.拷贝赋值运算符通常执行拷贝构造函数和析构函数中也要做的工作。这种情况下，公共的工作
   应该放在private的工具函数中完成。
