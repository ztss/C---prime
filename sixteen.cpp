16. 模板与泛型编程
16.1 定义模板
16.1.1 函数模板
   1.一个函数模板如下：
   template<typename T>
   int compare(const T &v1,const T &v2)
   {
     if(v1<v2)
     {
       return -1;
     }
     if(v2<v1)
     {
       return 1;
     }
     return 0;
   }
   2.在模板定义内，模板非类型参数是一个常量值。在需要常量表达式的地方，可以使用非类型参
   数。例如，指定数组大小。如下
   template<unsigned N,unsigned M>
   int compare(const char (&p1)[N],const char (&p2)[M])
   {
     return strcmp(p1,p2);
   }
   3.模板程序应该尽量减少对实参类型的要求。函数模板和类模板成员函数的定义通常放在头文件
   中。
