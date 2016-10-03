#include "graph.h"
std::istream &operator>>(std::istream &is ,Edge &e)
{
	is>>e.source>>e.destination>>e.weight;
	return is;
}
GraphPrt InitializeGraph(unsigned int NodeCount)
{
	GraphPrt G=new Graph;
	G->NodeCount=NodeCount;
	G->TheAdjacents=new List[G->NodeCount];
	for (unsigned int i=1;i<G->NodeCount+1;++i)
	{
		G->TheAdjacents[i]=new ListNode;
		G->TheAdjacents[i]->Next=nullptr;
	}
	return G;
}
Position Find(Vertex V,GraphPrt G)
{
	Position P;
	List L=G->TheAdjacents[V];
	P=L->Next;
	while(P)
		P=P->Next;
	return P;

}
void GraphAddNode(Edge E,GraphPrt G)
{
	if(E.weight==0) 
		return ;
	Position P=Find(E.source,G);
	if (P==nullptr){
		P=new ListNode;
		P->edges.source=E.source;
		P->edges.destination=E.destination;
		P->edges.weight=E.weight;
		P->Next=nullptr;
	}
}