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
