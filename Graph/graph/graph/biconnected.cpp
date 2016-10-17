#include"biconnected.h"
int biconnectedTableEntry::counter = 0;
Vertex biconnectedTableEntry::Start = 0;
biconnectedTablePrt InitBiconnectedTable(Vertex Start, GraphPrt G)
{
	 biconnectedTableEntry::Start = Start;
	biconnectedTablePrt T = new biconnectedTable[G->NodeCount];
	for (int i = 0; i < G->NodeCount; ++i)
	{
		T[i] = new biconnectedTableEntry;
		T[i]->header = new ListNode;
		T[i]->header = G->TheAdjacents[i];
		T[i]->visited = false;
		T[i]->parent = NotAVertex;
		T[i]->num = 0;
		T[i]->low = 0;
	}
	return T;
}
int min(int &a, int &b)
{
	return a < b ? a : b;
}
//���㷨�и�bug���Ƕ�������һ��������ʼ�㶼�ᱻ����Ϊ���
//��㣺
	//��������ĳ�ڵ�Ķ��Ӹ���Ϊ>1
	//��������ĳ�ڵ�Ķ��Ӹ���Ϊ1ʱ��vΪ���ڵ㣬wΪ���ӣ�low(w)>=num(v)
void findArt(Vertex V,biconnectedTablePrt T)
{
	
	T[V]->visited = true;
	biconnectedTableEntry::counter++;
	T[V]->low = T[V]->num = biconnectedTableEntry::counter;
	//printf("%d low is %d\n", V,T[V]->low);
	//printf("%d num is %d\n",V, T[V]->num);
	Position p = T[V]->header->Next;
	while (p)
	{
		Vertex W = p->destination;
		if (!(T[W]->visited))
		{
			T[W]->parent = V;
			findArt(W, T);
			if (T[W]->low >= T[V]->num &&V!=biconnectedTableEntry::Start)
			{
				printf("%d low is %d\n", W,T[W]->low);
				printf("%d num is %d\n",V, T[V]->num);
				printf("%d is an articulation point\n", V);
			}
			T[V]->low = min(T[V]->low, T[W]->low);
			//printf("%d low is %d\n",V, T[V]->low);

		}
		else
		{
			if (T[V]->parent != W) {
				T[V]->low = min(T[V]->low, T[W]->num);
				//printf("%d low is %d\n",V, T[V]->low);
			}
		}
		p = p->Next;
	}

}
void printLow(biconnectedTablePrt T,GraphPrt G)
{
	for (int i = 0; i < G->NodeCount; ++i)
	{
		printf("%d vertex low value is %d\n", i, T[i]->low);
	}
}
void printNum(biconnectedTablePrt T, GraphPrt G)
{
	for (int i = 0; i < G->NodeCount; ++i)
	{
		printf("%d vertex num value is %d\n", i, T[i]->num);
	}
}