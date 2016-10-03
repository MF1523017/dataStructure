#include "graph.h"
std::istream &operator>>(std::istream &is ,ListNode &e)
{
	is>>e.source>>e.destination>>e.weight;
	return is;
}
bool operator <(const ListNode &l1,const ListNode & l2)
{
	return l1.weight<l2.weight;
}
GraphPrt InitializeGraph(int NodeCount)
{
	GraphPrt G=new Graph;
	G->NodeCount=NodeCount;
	G->TheAdjacents=new List[G->NodeCount];
	//the i must begin at 0 ,or you will want to fuch the new result;
	for (int i=0;i<G->NodeCount;++i)//we think the Vertex begin in 0;
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
void GraphAddNode(ListNode E,GraphPrt G)
{
	if(E.weight==0) 
		return ;
	Position P=Find(E.source,G);
	if (P==nullptr){
		P=new ListNode;
		List L=G->TheAdjacents[E.source];
		P->source=E.source;
		P->destination=E.destination;
		P->weight=E.weight;
		P->Next=L->Next;
		L->Next=P;
	}
}