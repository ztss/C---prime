//17.12 17.13
#include<bitset>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

template<size_t N>
class quiz{
	public:
		quiz() : q() {};
		size_t getsize(){
			return N;
		}
		void set_solution(size_t n,bool b){
			q.set(n,b);
		}
		size_t get_score(const bitset<N>&);
	private:
		bitset<N> q;
};

template<size_t N>
size_t quiz<N>::get_score(const bitset<N>& a)
{
	size_t ret=0;
	for(size_t i=0;i<N;i++)
	{
		if(a[i]==q[i])
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	quiz<80> question;
	question.set_solution(0,1);
	question.set_solution(79,1);

	bitset<80> a;
	cout << question.getsize() << " " << question.get_score(a) << endl;
	return 0;
}
