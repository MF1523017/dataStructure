#pragma once
//biconnected 双连通性的
#include"graph.h"
struct  biconnectedTableEntry
{
	static Vertex Start;
	List header;
	bool visited;
	Vertex parent;
	int num;
	int low;
	static int counter;
};

extern const int NotAVertex;
extern const int Infinity;
typedef struct biconnectedTableEntry * biconnectedTable;
typedef biconnectedTable * biconnectedTablePrt;
biconnectedTablePrt InitBiconnectedTable(Vertex Start, GraphPrt G);
void findArt(Vertex V,biconnectedTablePrt T);
void printLow(biconnectedTablePrt T,GraphPrt G);
void printNum(biconnectedTablePrt T, GraphPrt G);