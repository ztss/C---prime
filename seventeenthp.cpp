17.标准库特殊设施
17.1 tuple类型
   1.可以将tuple理解为一个快速而随意的数据结构。
17.1.1 定义和初始化tuple
   1.如tuple<string,vector<double>,int,list<int>> someVal("cons",{3.13.2.3},42
     {1,2,3,4,5});
   2.tuple的默认构造函数是explicit的。所以不能使用赋值语句为tuple初始化。还可以使用make
   _tuple("string",12,20.00)来生成一个tuple。
   3.访问tuple成员可以使用get函数。如 auto book=get<0>(item)返回item的第一个成员。
   返回的是一个引用。如下语句可以得到tuple中成员的数目
   size_t sz=tuple_size<decltype(item)>::value;
   4.tuple可以让函数返回多个值。
17.2 bitset类型
17.2.1 定义和初始化bitset
   1.用unsighed的值初始化bitset。bitset<20> bitvec(0xbeef);也可以用包含0，1的字符串
   初始化bitset。
17.2.2 bitset操作
17.3 正则表达式
   1.正则表达式定义在regex头文件中。
17.3.1 使用正则表达式库
   1.一个正则表达式的语法是否正确是在运行的时候解析的。
   2.因为正则表达式是在运行的时候而不是在编译的时候运作的，所以我们应该明确的或者说很节
   省的使用正则表达式。
17.3.2 匹配与regex迭代器类型
17.3.4 使用regex_replace
17.4 随机数
   1.定义在头文件random中的随即库通过一组协作的类来解决这些问题，包含随机数引擎类和随机
   数分布类。
17.4.1 随机数引擎和分布
   1.我们可以如下代码生成一个随机数
   uniform_int_distribution<unsigned> u(0,9);//这是一个分布
   default_random_engine e;//生成无符号随机整数
   for(suze_t i=0;i<10;++i)
   {
     cout << u(e) << " ";
   }
   2.一个给定的随机数发生器会一直生成相同的随机数序列，一个函数如果定义了局部的随机数发
   生器，应该将其包括引擎和分布对象定义为static的。否则，每一次调用都会生成相同的序列。
   我们也可以使用随机数种子来达到这一目的。可以每次生成不一样的随机数。
17.4.2 其他随机数分布
17.5 IO库再探
17.5.1 格式化输入与输出
   1.在头文件iomanip中有setprecision可以改变精度。
17.5.2 未格式化的输入和输出操作
17.5.3 流随机访问
