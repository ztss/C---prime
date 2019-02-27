关联容器分为八种，主要表现在三个方面。（1）或者是一个set，或者是一个map（2）或者要求不
重复的关键字，或者允许重复关键字（3）按顺序保存元素，或者无序保存。允许重复关键字的容器
的名字都包含multi，不按关键字顺序存储的容器名字都以unordered开头。
11.1 使用关联容器
11.2 关联容器概述
11.2.1 定义关联容器
11.2.2 关键字类型的要求
   1.对于有序容器，关键字的类型必须定义元素比较的方法。
11.2.3 pair类型
   1.pair定义在头文件utility中。它的两个数据成员为first和second。可以用简单的成员访问
   符号访问。
   2.pair对象之间可以进行比较。
11.3 关联容器操作
11.3.1 关联容器迭代器
   1.一个map的value_type是一个pair，我们可以改变pair的值，但是不能改变关键字的值。
   2.set的迭代器是const的，智能用来读set中的元素，不能改变。
   3.map和set都支持begin和end操作。来取得一个迭代器。
   4.我们通常不对关联容器使用泛型算法。因为关键字是const意味着不能将关联容器传递给修改
   或者重排容器元素的算法。
11.3.2 添加元素
   1.可以用insert函数向关联容器中添加元素。insert函数返回一个pair，这个pair的first值
   是一个迭代器，指向具有给定关键字的成员，second成员是一个bool值，指出元素插入是否成功。
11.3.3 删除元素
   1.关联容器可以通过传递给erase一个迭代器或者一对迭代器来删除一个元素或者一个元素范围。
   函数返回void。关联容器还定义了另外一种erase函数，删除给定的关键字的对。返回被删除的
   对的数量。
11.3.4 map的下标操作
   1.c[k]或者c.at(k)。
11.3.5 访问元素
11.3.6 一个单词转换的map
11.4 无序容器
   1.在关键字类型的元素没有明显的序关系的情况下，无序容器是很有用的，通常会更简单，也会
   有更好的性能。

无论在有序还是无序容器中，具有相同关键字的元素都是相邻存储的。
