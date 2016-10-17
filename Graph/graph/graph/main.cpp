#include"graph.h"
#include"dijkstra.h"
#include"prim.h"
#include"biconnected.h"
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
int main(int argc,char ** argv)
{
	priority_queue<ListNode> p;
	
	GraphPrt G=InitializeGraph(7);
	ListNode e;
	
#if 0
	std::ifstream  input("graph.txt");//contain the graph info:source ,destination ,weight
	while(input>>e)
	{
		p.push(e);
		GraphAddNode(e,G);
	}
	while(!p.empty())
	{
		cout << p.top().weight << endl;
		p.pop();
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
#endif
#if 0
	std::ifstream  input("graphPrim.txt");//contain the graph info:source ,destination ,weight
	while (input >> e)
	{
		GraphAddNode(e, G);
	}
	Vertex Start;
	cout << "input the start Vertex: ";
	cin >> Start;
	PrimTablePrt T = InitPrimTable(Start, G);
	Prim(Start, G, T);
	PrintTreeEdge(G, T);
	PrintTreeValue(G, T);
#endif
	std::ifstream  input("graphBiconnected.txt");//contain the graph info:source ,destination ,weight
	while (input >> e)
	{
		GraphAddNode(e, G);
	}
	Vertex Start;
	cout << "input the start Vertex: ";
	cin >> Start;
	biconnectedTablePrt T = InitBiconnectedTable(Start, G);
	findArt(Start, T);
	//printLow(T, G);
	//printNum(T, G);
	return 0;
}