#include"dijkstra.h"
#include<iostream>
#include<queue>
TablePrt InitTable(Vertex Start,GraphPrt G)
{
	TablePrt T=new Table[G->NodeCount];
	for (int i=0;i<G->NodeCount;i++)
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
void PrintPath(Vertex v,TablePrt T)
{
	if(T[v]->Path!=NotAVertex)
	{
		PrintPath(T[v]->Path,T);
		printf(" to ");
	}
	printf("%d",v);
}
void Dijkstra(Vertex Start,GraphPrt G,TablePrt T)
{
	std::priority_queue<List>q;
	q.push(T[Start]->Header->Next);
	while(!q.empty())
	{
		Position P=q.top();
		q.pop();
		
		while(P)
		{
			T[P->source]->Known=true;
			if(!T[P->destination]->Known)
			{
				if(T[P->source]->Dist+P->weight<T[P->destination]->Dist)
				{
					T[P->destination]->Dist=T[P->source]->Dist+P->weight;
					T[P->destination]->Path=P->source;
					q.push(T[P->destination]->Header->Next);
				}
			}
			P=P->Next;
		}
	}
}