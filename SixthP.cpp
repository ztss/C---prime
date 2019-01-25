6.1 函数基础
   1.我们通过调用运算符来执行函数，调用运算符的形式是一对圆括号，作用于一个表达式，这个
   表达式是函数或者也可以是指向函数的指针；圆括号内部是用逗号隔开的实参列表。
   2.函数的调用分两步：首先实参初始化函数对应的形参，然后将控制权转交给被调用函数。此时
   主调函数被暂时中断，被调用函数开始执行。
   3.函数的返回类型不能是数组或者函数类型，但是可以返回指向数组或者函数的指针。
6.1.1 局部对象
   1.局部静态对象在程序的执行路径第一次经过对象定义语句时初始化，直到程序终止才被销毁，
   此对象所在的函数即使结束执行也不会对局部静态变量有影响。
6.1.2 函数声明
   1.函数也必须在使用之前声明，根据我们之前所说的，变量应该在头文件中声明，然后在源文件
   中定义，函数与之相同。所以定义函数的源文件应该把包含函数声明的头文件包含进来，然后编
   译器验证函数的声明与定义是否匹配。
6.1.3 分离式编译
   1.分离式编译允许我们把程序分割到几个文件中，每个文件单独编译。之所以使用分离式编译，
   因为当我们修改了一个源文件，只要重新编译那个改动的文件就可以了。可以节省很多时间，
   编译器会负责把对象文件链接到一起形成可执行文件。
6.2.1 传值参数
   1.当用指针作为形参的时候，给函数传递的是指针的副本，所以函数不会改变指针的值，但是可
   以改变指针所指对象的值。虽然这样可以达到改变对象的值的目的，但是在C++中，一般不这样
   使用，而是用引用类型的形参来代替指针。
6.2.2 传引用参数
   1.使用引用可以避免拷贝浪费空间时间，特别是对于大的容器。而且如果在函数中无须改变参数
   的值的时候，最好使用常量引用。
   2.可以使用引用类型返回函数的额外信息。比如说要写一个函数，他的作用是看一个字符串中是
   否有特定的字符串。并且还要返回特定字符串出现的次数。即返回两个值，这里可以用两种方法
   ，一种是定义一个struct,然后返回这个struct。另外一种就是传入函数的形参可以多传入一个
   引用类型的值，用来记录字符串出现的次数。
6.2.3 const形参和实参
   1.void func(const int i){};//func可以读取i,但是不能对i写值。
   如果这个时候再定义void func(int i){};C++虽然允许定义重名函数，但是需要形参列表不一
   样。这样定义的话因为顶层const被忽略了，所以会导致错误，即重复定义。
   2.形参的初始化方式和变量的初始化方式是一样的。把函数不会改变的形参定义成普通的引用是
   一种错误，因为这样会误导使用者，即函数可以修改它实参的值。而且使用引用却不使用常量引
   用会极大的限制函数所能接受的实参类型。即我们不能把const对象，字面值或者需要类型转换
   的对象传递给普通的引用形参。比如下面这个函数：
   string::size_type find_char(string &s,char c,string::size_type &occurs);这个函
   数只能作用于string对象，在这样调用的时候 find_char("hello,world!",'0',ctr)就会发
   生错误。因为"hello,world!"是字面值。而且这里会出现一个更加难以发现的错误。比如说：
   bool is_sentence(const string &s)
   {
     string::size_type ctr=0;
     if(find_char(s,'.',ctr)==s.size()-1&&ctr==1)
     {
       return true;//即当s只有末尾有.并且.只出现一次的时候判断它是一个句子。
     }
   }
   以上代码是错误的，因为find_char的string形参是普通引用。而is_sentence的是常量引用。
   这样在编译的时候就会出现错误了。所以牢记：把函数不会改变的形参定义成常量引用很重要。
6.2.4 数组形参
   1.不允许拷贝数组，所以使用数组的时候通常会将其转化为指针。数组是以指针的形式传递给函
   数的，所以函数一开始是不知道数组的长度的。所以调用者应该为此提供一些额外的参数。通常
   管理指针形参有三种方式：1).使用标记指定数组长度，即要求数组本省包含一个结束标志。典型
   的例子是C分格字符串，C风格的字符串存储在字符数组中，并且最后一个字符后面跟着一个空字
   符。所以函数在处理C风格字符串的时候遇到空字符串就停下。2).使用标准库规范，即同时传递
   数组的尾后指针。这里可以使用标准库函数begin(),end()传递数组的首元素和尾后元素的指针
   3).显式的传递一个表示数组大小的形参，即专门定义一个表示数组大小的形参。
   2.前面我们关于引用的讨论也适用与指针。当函数不需要对数组写操作的时候，数组的形参应该
   是指向const的指针。
   3.C++允许将变量定义为数组的引用，所以函数的形参也可以是数组的引用。比如以下;
   void print(int (&arr)[10])//arr这里是具有10个整数的整型数组的引用
   {
     for(auto i:arr)
     {
       cout<<i<<endll;
     }
   }
   但是这样就规定死了数组的大小，限制了函数的可用性。
   4.多维数组实际上就是数组的数组，所以将多维数组传递给函数的时候，真正传递的是数组首元
   素的指针，而它的首元素本身就是一个数组，指针就是一个指向数组的指针。而数组的第二维的
   大小是数组类型的一部分，所以不能省略，如下;
   void print(int (*matrix)[10],int rowsize){};这里matrix指向数组的首元素，该数组的
   元素是10个整数构成的数组。
6.2.5 main:处理命令行选项
6.2.6 含有可变形参的函数
   1.有时候我们无法得知应该向函数传递几个参数。比如说，想要编写能够输出程序产生的错误信
   息的函数，由于错误的种类很多，为了能够统一的处理错误信息。我们最好用一个函数实现此功
   能。而为了编写可以处理不同实参的函数，C++11新标准提供了两个方法，如果所有的实参类型
   相同，我们可以传递一个initializer_list的标准库类型；而如果实参的类型不同，那么我们
   可以编写另外一种特殊的函数，就是可变参数模板。而C++还有一种特殊的形参类型，即省略符，
   也可以用来传递可变数量的实参。然而这种功能一般只用于与C函数的交互接口程序。
   2.如果函数的实参数量未知但是全部实参的类型都相同，就可以使用initializer_list形参，
   它是一种标准库类型，用于表示某种特定类型的值的数组。定义在同名的头文件中。
   initializer_list<string> ls;
   initializer_list<int> li;
   可以看此类型与vector很像，但是initializer_list中的值是常量值，无法改变此对象内的值
   例如，输出错误信息的函数可以这样写，让它可以接受作用于可变数量的实参：
   void error_msg(initializer_list<string> li)
   {
     for(auto beg=li.begin();beg!=li.end();beg++)
     {
       cout<<*beg<<" ";
     }
     cout<<endl;
   }
   如果向initializer_list形参中传递一个值的序列。可以这样使用：
   if(expected!=actual)//expected和actual都是string对象
   {
     error_msg({"functionx",expected,actual});
   }
   else
   {
     error_msg({"functionx","okay"});
   }
   上面的代码我们都使用了error_msg函数，但是传递的参数数量却是不同的。
   3.省略符形参，这个功能仅仅用于C和C++通用的类型。特别应该注意的是，大多数类类型的对象
   在传递给省略符形参的时候都无法正确拷贝。
6.3.2 有返回值的函数
   1.不要返回局部对象的引用或者指针。函数完成后，所占用的存储空间也会被释放掉。因此，函
   数终止意味着局部变量的引用将指向不再有效的内存区域。
   2.如果函数返回的是引用类型，并且不是常量引用，那么我们可以为函数的结果赋值。
6.3.3 返回数组指针
   1.数组不能被拷贝，所以函数不能返回数组。但是函数可以返回数组的指针或者引用。
   2.声明一个返回数组指针的函数如右式所示 Type(*function(parameter_list))[dimension]
   3.C++11有一个新标准，可以用尾置返回类型，即trailing return type。如下所示：
   auto func(int i)->int(*)[10];//返回一个函数10个整数数组的指针
6.4 函数重载
   1.如果在同一个作用域，函数的名字相同但是形参列表不同，称这种为函数重载。但是main函数
   不能重载。如果两个函数除了返回类型以外所有的要素都相同。这样是不行的。
   2.顶层的const形参不影响传入函数的对象。一个有顶层const的形参无法和另外一个没有顶层
   const的形参区分开来。如
   Record lookup(phone*);
   Record lookup(phone* const);//重复声明
   但是另一方面，如果形参是某种类型的指针或者引用，那么可以通过区分其指向的是常量对象还
   是非常量对象可以实现函数重载，此时的const是底层的。如下：
   Record lookup(Account*);
   Record lookup(const Account*);//作用与指向常量的指针
   对于上面两个函数，由于常量对象不能转换为其他类型，所以只能把const对象传给const形参，
   但是非常量可以转换为const,所以上面两个函数都可以传递入非const对象。而第一个函数不能
   传入const对象。但是一般我们传递一个非常量对象的时候，编译器会优先选择非常量版本的函
   数。
   3.（const_cast的用法）我们之前讲过这样的函数：
   const string &get_Shorter(const string &str1,const string &str2)
   {
     return str1.size>str2.size?str2:str1;
   }
   这个函数的参数以及返回类型都是const string的引用。根据上面我们的讨论，我们将两个非
   常量的对象传入get_Shorter。，但是我们返回的结果却是const string的引用。所以我们需要
   函数，当传递的参数为非常量的时候，得到的是普通的引用。这个时候我们可以使用const_cast
   string get_Shorter(string &str1,string &str2)
   {
     auto &r=get_Shorter(const_cast<const string &>(str1),const_cast<const string &>(str2));
     return const_cast<string &>(r);
   }
   上面这个函数首先将它传入的形参变为常量形式，然后调用get_shorter函数的const版本，这个
   时候返回的是const string。但是给引用是绑定在了一个非常量的形参上面，所以最后再用
   const_cast转换为普通的string&。
   4.定义了一组重载函数之后，就可以根据通过传递合理的实参调用这些函数。函数匹配就是指的
   这个过程，也可以叫做重载确定。一般这个过程都是很好确认的，但是当两个重载函数参数数量
   相同并且可以相互转换的时候，这个就有点困难了。函数重载有三种结果：编译器找到一个匹配
   的函数；编译器找不到匹配的函数；编译器找到多于一个重载函数，这个时候就会发生错误，称
   为二义性调用(ambiguous call)。
6.4.1 重载与作用域
   1.如果我们在内层作用域中声明名字，它将隐藏外层域中声明的共同实体。在不同的作用域中无
   法重载函数名。即如果在内层声明一个和外层一样的函数名字，那么在这个内层就不能使用外层
   的函数。
6.5.1 默认实参
   1.如果函数的形参在很多次调用中都被赋予同一个值，那么把这个反复出现的值称为函数的默认
   实参。而且此时这个函数也能接受用户指定的值。但是必须要注意的是一旦定义了一个默认形参
   它后面的所有形参都必须要有默认值。
   2.如果想使用默认实参，那么在调用函数的时候忽略该实参就可以了。在设计含有默认实参的函
   数的时候，应该让经常使用默认实参的形参在后面，而不怎么使用默认实参的形参在前面。
   3.在给定的作用域中一个形参只能被赋予一次默认实参。所以函数重载需要注意。通常在函数声
   明中指定默认实参，并且将该声明放在合适的头文件中。
   4.局部变量不能作为默认实参。
   5.默认实参一般在什么情况下很有作用呢？比如说我们要写一个函数。这个函数大多数都用一个
   默认实参，但是只有小部分使用特例，这个时候如果定义默认实参就可以省略一个形参的初始化
   而只有小部分情况我们使用自己定义的参数去初始化这个默认形参。比如写一个函数写出一个单
   词的复数形式。
6.5.2 内联函数和constexpr函数
   1.一般我们可以把一些小操作定义为函数，这可以让我们更加好的理解程序，也能更易于修改，
   但是函数调用会消耗掉很多时间，比直接求等价的表达式的时间要长。因为一次函数调用包含很
   多工作，比如保存寄存器，并在返回时恢复，也需要拷贝实参，程序再转入新的位置执行。但是
   这个时候我们可以将操作较小的函数指定为内联函数，即在函数的调用点处内联的展开，就相当
   于将函数变成了表达式运行，可以省略函数运行的开销。在函数前面加上inline就能声明成内联
   函数了。一般的，内联机制用于优化规模较小，调用频繁的函数。很多编译器不支持内联递归函
   数。
   2.内联函数通常放在头文件之中。而且它的定义一般也放在头文件中。
6.5.3 调试帮组
   1.在开发大型项目的时候，程序员有时会用到一种类似于头文件保护的技术，以便有选择的调试
   代码，即程序中包含调试的代码，但是这些代码只在开发程序的时候用。当程序开发完准备发布
   的时候，要先屏蔽掉调试代码。这种方法用到了两项预处理功能：assert和NDEBUG。
   2.assert预处理宏，即一个预处理变量。assert宏使用一个表达式作为他的条件：assert(expr)
   首先对表达式求值，如果表达式为假，assert输出信息并终止程序的运行，如果表达式为真，
   assert什么也不做。定义在cassert头文件中，由预处理器而非编译器处理。assert宏一般用于
   检查“不能发生”的条件。例如对输入文本进行操作的程序要求所有给定的单词长度都大于某个阈
   值。即assert(word.size()>threshold)。
   3.assert的行为依赖于一个名为NDEBUG的预处理变量的状态，如果定义了NDEBUG，那么assert
   什么也不做。默认状态下没有定义NDEBUG，此时assert发挥作用。如果使用#define语句定义
   NDEBUG，就可以关闭调试状态。
   4.我们也可以用NDEBUG编写自己的条件调试代码，如果NDEBUG没有定义，就会执行#ifndef和
   #endif之间的代码。如果定义了NDEBUG，那么这些代码就会被忽略。
   void print(const int ia[],size_t size)
   {
     #ifndef NDEBUG//_ _ func_ _输出当前调试的函数的名字。
     cerr << _ _fun_ _ << ":array size is " << size << endl;
     #endif
   }
   编译器为每个函数都定义了_ _func_ _，此为const char的一个静态数组。用于存放函数的名
   字。C++编译器还定义了4个用于程序调试的很有用的名字。
6.6 函数匹配
   1.下面有一组函数以及调用
   void f();
   void f(int);
   void f(int ,int);
   void f(double,double=3.14);
   f(5.6);//会调用void f(double,double)
   一般函数匹配分为两步，第一步确定本次调用对应的重载函数集，需满足两个条件分别是与调用
   函数同名，然后就是其声明在调用点可见。第二步看函数调用提供的实参，一般也必须具有两个
   特征，形参的数量与本次调用提供的实参数目相等，然后就是实参的类型与对应的形参类型一样
   或者可以转换。所以上述给出的调用，首先给了一个实参，所以排除形参数目不对应的，即第一
   个和第四个。然后就是观察第四个函数，函数给定了一个默认形参，所以只用一个实参也可以调
   用他。即这个时候我们需要一个注意事项(如果函数含有一个默认形参，那么我们调用函数的时
   侯传入的实参数目少于实际使用的实参数目也可以)。这两步确定候选函数，最后考察最佳匹配
   函数，寻找最佳匹配的基本思想是实参的类型与实参类型越接近越好。这个时候可以再看一个调
   用，比如说f(42,2.56)。这个函数调用有两个候选函数，但是候选函数不能挑选出最佳匹配，因
   为第三个和第四个都匹配一个实参，所以编译器不能找到最佳的匹配，所以这个时候编译器就会
   报错。这个给我们的忠告就是我们在调用重载函数的时候应该尽量避免强制类型转换。
6.6.1 实参类型转换
   1.函数的形参是顶层const的话，就无法与另一个重载函数区分，所以这种行为是非法的。比如
   int calc(char*,char*);
   int calc(char* const, char* const);
   顶层const指的是指针本身是常量。即*const这种类型。
6.7
   1.函数的类型由它返回的类型和形参的类型共同决定，与函数名无关。函数指针即指向某种特定
   的函数类型。
   2.函数指针的定义：bool (*pf)(const string &,const string &);
   3.函数指针的使用：当我们把函数名作为一个值使用的时候，该函数自动转换为指针。
   pf=lengthCompare;
   还可以直接使用指向函数的指针调用该函数，不需要提前解引用指针
   bool b1=pf("hello","goodbye");
