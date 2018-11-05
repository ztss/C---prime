3.34.此程序的功能是将p1所指向的位置变为p2所指向的位置。
3.35
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;


int main()
{
int data[10];
for(int i=0;i<10;i++)
{
data[i]=i;
}
int *t1=begin(data);
int *t2=end(data);
while(t1!=t2)
{
*t1=0;
t1++;
}
for(auto i:data)
{
cout<<i<<endl;
}
return 0;
}

3.36
这里比较两个vector是否相等，使用迭代器。
