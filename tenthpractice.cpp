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
