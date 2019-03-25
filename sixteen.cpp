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
16.1.2 类模板
   1.如下是一个类模板
   template<typename T> class Blob{
	 public:
		typedef T value_type;
		typedef typename vector<T>::size_type size_type;
		Blob();
		Blob(initializer_list<T> il);
		size_type size() const
		{
			return data->size();
		}
		bool empty() const
		{
			return data->empty();
		}
		void push_back(const T &t)
		{
			data->push_back(t);
		}
		void pop_back();
		//元素访问
		T& back();
		T& operator[](size_type i);
	private:
		shared_ptr<vector<T>> data;
		void check(size_type i,const string &msg) const;
   };
   一个类模板的每一个实例都形成一个独立的类。每一个类与其他类型都没有任何关联。
   2.默认情况下，对于一个实例化的类模板，其成员只有在使用时才被实例化。
16.1.3 模板参数
16.1.4 成员模板
   1.一个类可以包含本身是模板的成员函数。这种成员叫做成员模板。成员模板不能是虚函数。
16.1.5 控制实例化
16.1.6 效率与灵活性
16.2 模板实参推断
16.2.1 类型转换与模板类型参数
   1.只有有限的集中类型转换会应用于模板函数形参，因为编译器通常不是对实参进行类型转换，
   而是生成一个新的模板实例。如const转换和数组或函数到指针的转换可以应用于模板函数形参
   类型转换。其他的如算术转换，派生类向基类的转换以及用户定义的转换都不能应用于函数模板。
16.2.2 函数模板显式形参
16.2.3 尾置返回类型与类型转换
   1.如下：
   template<typename T>
   auto fcn(T beg,T end)->decltype(*beg)
   {
     return *beg;
   }
   2.有些时候我们无法直接获得所需要的类型，比如说我们可以能编写一个类似如上的函数，但是
   我们不是需要引用，而是元素的值。我们可以使用头文件<type_traits>。如下：
   remove_reference<decltype(*beg)>::type。所以上述函数可以改写如下：
   template<typename T>
   auto fcn(T beg,T end)->remove_reference<decltype(*beg)>::typedef{
     retrun *beg;
   }
   此函数返回一个元素的拷贝。
16.2.4 函数指针和实参推断
   1.当参数是一个函数模板实例的地址的时候，程序的上下文必须满足，对于每个模板参数，能唯
   一确定其类型或值。如下
   template<typenam T> int compare(const T&,const T&)
   void func(int(*)(const string&,const string&));//这是一个函数，其实参是函数指针
   void func(int(*)(const T&,const T&));
   func(compare);//error
   func(compare<int>)
16.2.5 模板实参推断和引用
   1.如果一个函数参数是指向模板参数类型的右值引用如T&&,则可以传递给它任意类型的实参。如
   果将一个左值传递给这样的参数，则函数参数被实例化为一个普通的左值引用。
16.2.6 理解std::move
16.2.7 转发
   1.forward和move一样，定义在<utility>头文件中。
16.3 重载和模板
16.4 可变参数模板
16.4.1 编写可变参数函数模板
16.4.2 包扩展
16.4.3 转发参数包
16.5 模板特例化
