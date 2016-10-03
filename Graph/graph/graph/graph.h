#ifndef GRAPH_H
#define GRAPH_H
#include<istream>
typedef int Vertex;
struct Edge
{
	Vertex source;
	Vertex destination;
	int weight;//if weight ==0,we believe source == destination
};
std::istream &operator>>(std::istream &is ,Edge &e);

struct ListNode;
typedef ListNode * List;
typedef List Position;
typedef List * ListPrt;
typedef Edge * EdgePrt;
struct ListNode
{
	EdgePrt edges;
	List Next;
};

bool operator <(const ListNode &l1,const ListNode & l2);
struct Graph
{
	unsigned int NodeCount;
	ListPrt TheAdjacents;
};
typedef Graph * GraphPrt;
GraphPrt InitializeGraph(unsigned int NodeCount);
void GraphAddNode(Edge E,GraphPrt G);
#endif