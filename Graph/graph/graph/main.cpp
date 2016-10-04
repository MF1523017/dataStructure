#include"graph.h"
#include"dijkstra.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

int main(int argc,char ** argv)
{
	
	GraphPrt G=InitializeGraph(7);
	ListNode e;
	std::ifstream  input("graph.txt");//contain the graph info:source ,destination ,weight
	while(input>>e)
	{
		GraphAddNode(e,G);
	}
	Vertex Start;
	cout<<"input the start Vertex: ";
	cin>>Start;
	TablePrt T=InitTable(Start,G);
	Dijkstra(Start,G,T);
	cout<<"input the end Vertex: ";
	Vertex End;
	cin>>End;
	PrintPath(End,T);
	PrintDist(End,T);
	return 0;
}