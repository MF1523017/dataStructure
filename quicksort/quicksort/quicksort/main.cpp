#include"quicksort.h"
#include<ctime>
#include<cstdlib>
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	vector<int> a({ 2,5,1,8,4,3,7,10,200,9,90,89,32 });
	srand((unsigned)time(nullptr));
	for (int i = 0; i < 100000; ++i)
		a.push_back(rand());
	clock_t start = clock();
	quicksort(a,0,a.size()-1);
	clock_t	 end = clock();
	cout << "runtime is " << end - start << endl;
	//for (auto i : a)
	//	cout << i << " ";
	return 0;
}