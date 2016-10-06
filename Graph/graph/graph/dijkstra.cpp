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
	std::priority_queue<ListNode>q;//only ListNode works
	q.push(*(T[Start]->Header->Next));//the first ListNode values;
	bool firstElement = true;//the start Vertex processes flag
	while(!q.empty())
	{
		ListNode L=q.top();//pop the smallest weight values' ListNode Vertex 
		q.pop();
		Position P;
		if(firstElement){//Start Vertex
			P = T[Start]->Header->Next;
			firstElement = false;
		}
		else//other Vertex
			P = T[L.destination]->Header->Next;//P point to the destination Vertex
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
					q.push(*(P));//push the neartest Vertex
				}
			}
			P=P->Next;
		}
	}
}