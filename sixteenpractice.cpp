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
   2.
