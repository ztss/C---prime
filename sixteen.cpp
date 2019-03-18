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
