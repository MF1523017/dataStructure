#include"dijkstra.h"
#include<iostream>
#include<queue>
TablePrt InitTable(Vertex Start,GraphPrt G)
{
	TablePrt T=new Table[G->NodeCount];
	for (unsigned int i=1;i<G->NodeCount+1;i++)
	{
		T[i]=new TableEntry;
		T[i]->Header=new ListNode;
		T[i]->Header=G->TheAdjacents[i];
		T[i]->Known=false;
		T[i]->Dist=Infinity;
		T[i]->Path=NotAVertex;
	}
	T[Start]->Dist=0;
	return T;
}
void Dijkstra(Vertex Start,GraphPrt G,TablePrt T)
{
	std::priority_queue<List>q;
	q.push(T[Start]->Header->Next);
	while(!q.empty())
	{
		Position P=q.top();
		q.pop();
		T[P->edges->source]->Known=true;
		while(P)
		{
			if(!T[P->edges->destination]->Known)
			{
				if(T[P->edges->source]->Dist+P->edges->weight<T[P->edges->destination]->Dist)
				{
					T[P->edges->destination]->Dist=T[P->edges->source]->Dist+P->edges->weight;
					T[P->edges->destination]->Path=P->edges->source;
					q.push(T[P->edges->destination]->Header->Next);
				}
			}
			P=P->Next;
		}
	}
}