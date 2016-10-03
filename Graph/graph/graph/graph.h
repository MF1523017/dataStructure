#ifndef GRAPH_H
#define GRAPH_H
#include<istream>
typedef int Vertex;

struct Graph;
struct ListNode;
typedef struct ListNode * List;
typedef List Position;
typedef List * ListPrt;
typedef struct Graph * GraphPrt;
struct ListNode
{
	Vertex source;
	Vertex destination;
	int weight;//if weight ==0,we believe source == destination
	List Next;
};
std::istream &operator>>(std::istream &is ,ListNode &e);

bool operator <(const ListNode &l1,const ListNode & l2);
struct Graph
{
	int NodeCount;
	ListPrt TheAdjacents;
};

GraphPrt InitializeGraph(int NodeCount);
void GraphAddNode( ListNode L,GraphPrt G);
#endif