#include"graph.h"
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
int main(int argc,char ** argv)
{
	GraphPrt G=InitializeGraph(7);
	Edge e;
	while(cin>>e)
	{
		GraphAddNode(e,G);
	}
	return 0;
}