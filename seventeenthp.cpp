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
