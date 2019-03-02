12.1 动态内存与智能指针
   1.new 在动态内存中为对象分配空间并且返回一个指向该对象的指针。delete 接受一个动态对
   象的指针，销毁该对象，并且释放与之相关的内存。可以使用memory的头文件管理动态内存。
12.1.1 shared_ptr类
   1.定义和默认初始化：shared_ptr<string> pl;shared_ptr<list<int>> p2;
   2.auto p6=make_shared<vector<string>>();
   3.当指向一个对象的最后一个shared_ptr被销毁的时候，shared_ptr类会自动销毁此对象，是
   通过析构函数完成此工作的。
   4.程序之所以使用动态内存基于这些原因：程序不知道自己需要多少对象，程序不知道所需对象
   的准确类型，程序需要在多个对象间共享数据。
12.1.2 直接管理内存
   1.可以使用new,delete管理内存。
12.1.3 shared_ptr和new结合使用
12.1.4 智能指针和异常
   1.智能指针使用的时候需要注意以下事项：不使用相同的内置指针值初始化（或者reset）多个
   智能指针。不适用get()初始化或者reset另一个智能指针。
12.1.5 unique_ptr
   1.unique_ptr必须使用new初始化。
12.1.6 weak_ptr
   1.weak_ptr指向一个由shared_ptr管理的对象。将一个weak_ptr绑定到一个shared_ptr不会
   改变shared_ptr的引用计数。
   2.由于对象可能不存在，所以不能使用weak_ptr直接访问对象，必须调用lock()，这个函数会
   检查weak_ptr指向的对象是否存在，如果存在，返回一个指向共享对象的shared_ptr。
12.2 动态数组
12.2.1 new和数组
12.2.2 allocator类
12.3 使用标准库：文本查询程序
12.3.1 文本查询程序设计
