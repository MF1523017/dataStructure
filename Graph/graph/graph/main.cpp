#include"graph.h"
#include"dijkstra.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
#if 0
struct b{
	int a;
};
typedef struct b * A;
void test(A aa)
{
	for(int i=0;i<10;i++)
	{
		aa[i].a=i;
	}
}
#endif
int main(int argc,char ** argv)
{
#if 0
	A aa;
	test(aa);
	for (int i=0;i<10;i++)
		cout<<aa[i].a<<endl;
#endif
	GraphPrt G=InitializeGraph(7);
	ListNode e;
	std::ifstream  input("graph.txt");
	while(input>>e)
	{
		GraphAddNode(e,G);
	}
	Vertex Start=1;
	TablePrt T=InitTable(Start,G);
	Dijkstra(Start,G,T);
	PrintPath(5,T);
	return 0;
}