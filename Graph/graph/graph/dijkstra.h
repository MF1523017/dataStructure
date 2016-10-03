#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include"graph.h"
struct TableEntry
{
	List Header;
	bool Known;
	int Dist;
	Vertex Path;
};
const int NotAVertex=-1;
const int Infinity=1000000;
typedef struct TableEntry * Table;
typedef Table * TablePrt;
TablePrt InitTable(Vertex Start,GraphPrt G);
void PrintPath(Vertex V,TablePrt T);
void Dijkstra(Vertex Start,GraphPrt G,TablePrt T);
#endif