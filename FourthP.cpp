4.1.1 基本概念
   1.一元运算符以及二元运算符，还有三元运算符。函数调用也是一种特殊的运算符，且对运算
   对象的数量没有限制。
   2.对于运算符重载，只能改变运算对象的类型以及返回值的类型，但是运算对象的个数，运算符
   的优先级和结合律是无法被改变的。
   3.关于左值和右值，当一个对象被用作右值的时候，我们使用的是对象的值，而当对象被用作
   左值的时候，用到的是对象在内存中的地址。
4.1.2 优先级与结合律
   1.对于*vec.begin(),先算vec.begin(),再解引用。
   2.对于形如f()+g()*h()+j()这样的表达式，如果f,g,h,j是无关的函数。那么函数的调用顺序
   不会受到限制，但是如果某几个函数影响同一个对象，那么他就是错误的表达式。所以，当我们
   不能确定运算顺序的时候最好用括号强制改变表达式。
4.2 算术运算符
   1.一元运算符的优先级最高。
   2.注意 bool b=true;bool b2=-b;这里b2是真，因为b2不等于0。
   3.C++11新规定商一律向0取整，就是直接丢弃小数部分。
4.3 逻辑和关系运算符
   1.逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，当左侧运算
   符不能确定表达式的值的时候才会计算右侧的表达式的结果。
   以下的代码：
   for(const auto &str:vec)
   {
     cout<<s;
     if(s.empty()||s[s.size()-1]=='.')
     {
       cout<<endl;
     }
     else
     {
       cout<<" ";
     }
   }
   上面的代码str被声明为引用类型，是因为vec的对象是string，可能非常的大，所以将str声明
   为引用类型可以避免拷贝元素，这里需要加上const,不允许改变str。
4.4 赋值运算符
   1.C++11允许使用花括号括起来的初始值列表作为赋值语句的右侧对象。就是说可以用它对一个
   vector赋值。
4.5 递增和递减运算符
   1.除非必须，不要使用递增递减运算符的后置版本，这里的意思就是说不要使用。
   2.在一种情况可以使用后置递增递减符号，这是为了追求简洁。比如说
   auto vbegin=vec.begin();
   while(vbegin!=vec.end()&&*vbegin>=0)
   {
     cout<<*vbegin++<<endl;
   }//输出vec里面的值，直到遇到一个负值。
   这里由于后置递增递减运算符优先级大于解引用符号，所以*vbegin++，先对vbegin加1，然后
   返回vbegin初始值的副本作为解引用符号的对象，所以这里输出的是vbegin开始指向的值。
4.6 成员访问运算符
   1.解引用运算符的优先级较低，所以一般加上括号。
4.7 条件运算符
   1.由于条件运算符的优先级很低，所以一般在条件运算符两边加上括号。
4.8 位运算符
   1.由于使用位运算符可能会改变整数的符号，所以一般建议只将位运算符用于处理无符号类型。
   2.二进制位向左移或者向右移，移出边界之外的位就被舍弃掉了。
   3.一般位运算符会将它操作的数变为int在执行位操作。
