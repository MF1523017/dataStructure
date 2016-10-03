#include "graph.h"
std::istream &operator>>(std::istream &is ,Edge &e)
{
	is>>e.source>>e.destination>>e.weight;
	return is;
}
bool operator <(const ListNode &l1,const ListNode & l2)
{
	return l1.edges->weight<l2.edges->weight;
}
GraphPrt InitializeGraph(unsigned int NodeCount)
{
	GraphPrt G=new Graph;
	G->NodeCount=NodeCount;
	G->TheAdjacents=new List[G->NodeCount];
	for (unsigned int i=1;i<G->NodeCount+1;++i)//we think the Vertex is larger 0
	{
		G->TheAdjacents[i]=new ListNode;
		G->TheAdjacents[i]->edges=new Edge;
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
		List L=G->TheAdjacents[E.source];
		P->edges=new Edge;
		P->edges->source=E.source;
		P->edges->destination=E.destination;
		P->edges->weight=E.weight;
		P->Next=L->Next;
		L->Next=P;
	}
}