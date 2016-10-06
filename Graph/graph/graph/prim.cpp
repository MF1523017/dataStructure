#include"prim.h"
#include<iostream>
#include<queue>
PrimTablePrt InitPrimTable(Vertex Start, GraphPrt G)
{
	PrimTablePrt T = new PrimTable;
	for (int i = 0; i < G->NodeCount; ++i)
	{
		T[i] = new PrimTableEntry;
		T[i]->Header = new ListNode;
		T[i]->Header = G->TheAdjacents[i];
		T[i]->Known = false;
		T[i]->Dist = Infinity;
		T[i]->Path = NotAVertex;
	}
	T[Start]->Dist = 0;
	return T;
}
void Prim(Vertex Start, GraphPrt G, PrimTablePrt T)
{
	std::priority_queue<ListNode> p;//only ListNode works
	p.push(*(T[Start]->Header->Next));//the first ListNode values;
	bool firstElement = true;//the start Vertex processes flag
	while (!p.empty())
	{
		ListNode L = p.top();//pop the smallest weight values' ListNode Vertex 
		p.pop();
		Position tmp;
		if (firstElement) {//Start Vertex
			firstElement = false;
			tmp = T[Start]->Header->Next;
		}
		else//other Vertex
			tmp = T[L.destination]->Header->Next;//tmp point to the destination Vertex
		while (tmp)
		{
			Vertex src = tmp->source;
			Vertex dst = tmp->destination;
			T[src]->Known = true;
			if (!T[dst]->Known)
			{
				if (tmp->weight < T[dst]->Dist)//update the Dist
				{
					T[dst]->Dist = tmp->weight;
					T[dst]->Path = src;
					p.push(*tmp);
				}
			}
			tmp = tmp->Next;
		}
	}
}
void PrintTreeValue(GraphPrt G, PrimTablePrt T)
{
	int treeValue = 0;
	for (int i = 0; i < G->NodeCount;++i)
	{
		treeValue += T[i]->Dist;
	}
	printf("\nTreeValue is %d\n", treeValue);
}
void PrintTreeEdge(GraphPrt G, PrimTablePrt T)
{
	printf("\nMinTree's Edge is \n");
	for (int i = 0; i < G->NodeCount; i++)
	{
		if (T[i]->Path == NotAVertex)
			continue;
		else
		{
			printf("(%d,%d)", i, T[i]->Path);
		}
	}
}