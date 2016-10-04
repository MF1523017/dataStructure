#include"dijkstra.h"
#include<iostream>
#include<queue>
//InitTable we new NodeCount Tables to store the info of Dijkstra algorithm
//PrintPath :give any Vertex v ,we print the real path ,from Vertex Start to it;
//			 Iteration is a good chioce;  
//Dijkstra:we use the priority_queue to store the nearest neighbors 
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
	if(T[v]->Path!=NotAVertex)//NotAVertex is the Vertex Start flag 
	{
		PrintPath(T[v]->Path,T);
		printf(" to ");
	}
	printf("%d",v);
	
}
void PrintDist(Vertex v,TablePrt T)
{
	printf("\nthe distance is %d\n",T[v]->Dist);
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
			Vertex src=P->source;//source Vertex
			Vertex dst=P->destination;//destination Vertex
			T[src]->Known=true;
			if(!T[dst]->Known)
			{
				if(T[src]->Dist+P->weight<T[dst]->Dist)//update the dist
				{
					T[dst]->Dist=T[src]->Dist+P->weight;
					T[dst]->Path=src;
					q.push(T[dst]->Header->Next);//push the neartest Vertex
				}
			}
			P=P->Next;
		}
	}
}