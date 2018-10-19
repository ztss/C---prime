/***
第三章
****/
3.2.1 定义和初始化string对象
   1.string s4(10,'c');s4为cccccccccc。
   2.使用等号初始化一个变量，执行的时拷贝初始化。如果不使用等号，则执行直接初始化，当
   初始值有多个的时候，使用直接初始化。
3.2.2 string对象上的操作
   1.<=利用字符的字典序顺序比较，并且对字母大小写敏感。
   2.读写string对象的时候，如string s;cin>>s。字符串会忽略开头的空白（空格符，换行
   符，制表符），从第一个真正的字符开始，直到遇到下一处空白。
   3.	string str;
	    while(cin>>str)
	    {
		     cout<<str<<" "<<str.size()<<endl;
	    }这段代码读取流，如果没有遇到文件结束标志或者非法输出，那么会一直运行下去。
   4.有时候我们希望可以保留输入时候的空白符。这个时候可以用getline函数代替>>。函数从
   给定的输入流中读入内容。直到遇到换行符，就返回结果。即string str;getline(cin,li
   ne)。触发getline函数返回结果的换行符实际上被丢弃掉了。得到的string对象中不包含该
   换行符。
   5.string::size_type。size()函数返回值的类型是string::size_type。这中类型很明显是
   无符号类型。混用有符号数和无符号数有时候会产生一些奇怪的结果，假设n是一个负值的int。
   则s.size()<n几乎肯定是true。因为n会自动转换为一个无符号值。0
   6.因为c++为了能和c兼容，所以c++语言的字符串字面值并不是标准库类型string的对象。所以
   对这些字符串字面值不能直接用加号。
   7.C++除了定义C++语言特有的功能外，也兼容了C语言的标准库。C语言的头文件一般是name.h，
   C++则命名为cname。c表示这个是属于c语言标准库的头文件。两个头文件的内容是一样的。但是
   cname的头文件中定义的名字属于命名空间std，而。h文件则不是。C++程序员一般使用cname。
   8.C++提供一种语句：范围for语句。形式为：
                  for(declaration:expression)
                     statement
   其中，expression是一个对象，永不表示一个序列。declaration表示一个变量，负责访问
   序列中的基础元素。如：
                 string str="hello,world!";
                 for(auto c:str)
                 {
                   cout<<c<<endl;//输出str中的每个字符。
                 }
   或者
   #include<iostream>
   #include<string>
   #include<cctype>
   using namespace std;

   int main()
   {
     string str="hello,world!!!!!";
     decltype(str.size()) punct_cnt=0;//将punct_cnt定义为跟str.size()一样的类型。
     for(auto c:str)
     {
       if(ispunct(c))//c是否是标点符号
     {
        punct_cnt++;
     }
   }
   cout<<punct_cnt<<endl;
   return 0;
 }
3.3.1 定义和初始化vector对象
   1.（1）vector<T> v2(v1) v2中包含v1所有元素的副本
     （2）vector<T> v3(n,val) v3中包含n个重复的元素，每个元素的值都是val
     （3）vector<T> v4{a,b,c,.....} v5中包含了初始个值的元素，每个元素被赋予相应的
      初始值。
3.3.2 向vector元素中添加元素
   1.如果循环体内部包含向vector中添加元素的语句，则不能使用范围for语句【3.2.2.8】。
   注意：范围for语句内不应该改变其所遍历序列的大小。c++中vector对象能够高效率的增长，
   所以一般有效的方法时在运行的时候动态的向vector对象中添加元素。
3.3.3 其他vector操作
   1.（1）v[n] 返回v中第n个位置元素的引用。
     （2）v1={a,b,c...} 用列表中的元素拷贝替换v1中的元素。注意这里列表中的元素要与v1
      中的元素个素相同。
   2.可以使用范围for语句访问vector对象中元素的值。
   3.vector元素之间的比较通过字典顺序比较。这里要注意，使用比较符号比较大小只能在vector
   元素相对应的类定义了比较大小符号的时候才能使用。
   4.vector不能使用下标去初始化。而且对vector对象执行下标操作的时候，必须确定这里的值
   已经存在。否则如果通过下标访问了不存在元素，那么就会产生缓冲区溢出[buffer overflow]
   的严重的后果。而确保下标合法的一种有效手段就是使用范围for语句。
   5.vector以及string对象的下标运算符可以用于访问已存在的元素，而不能用于添加元素。
