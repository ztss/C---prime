//p10.3
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	cout << accumulate(vi.cbegin(),vi.cend(),0) << endl;
	return 0;
}

//p10.5
c风格字符串由于没有重载==，所以只有当两个字符串的指针值相同，即地址值相同的时候才会返回
true。而当两个序列指针不同时，就算字符串完全相同，也不相等。

//10.8
因为标准库算法从不直接操作容器，只是操作迭代器，从而间接访问容器。能不能插入或者删除元素
不在于算法，而在于传递给这些算法的迭代器是否有这样的能力。而back_inserter就有这样的能力
back_inserter在头文件<iterator>中。
