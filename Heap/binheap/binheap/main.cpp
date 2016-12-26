#include"binHeap.h"
#include<iostream>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	int a[7] = { 5,2,3,4,1,90,80 };
	PriorityQueue H = Initialize(10);
	MakeEmpty(H);
	for (auto n : a)
		Insert(n, H);
	while (true)
	{
		ElementType n = DeleteMin(H);
		if (n== MinData)
			break;
		cout << n << endl;
	}
	Destory(H);
	return 0;
}