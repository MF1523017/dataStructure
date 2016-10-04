#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include"graph.h"
//TableEntry info: the header point to nearest neighbors
//					Known records whether the Vertex is known or not; 
//					Dist add up the distance of the start Vertex to other Vertexes;
//					Path records the real path with Vertex start to the end;
struct TableEntry
{
	List Header;
	bool Known;
	int Dist;
	Vertex Path;
};
const int NotAVertex=-1;
const int Infinity=0xffffffff/2;
typedef struct TableEntry * Table;
typedef Table * TablePrt;
TablePrt InitTable(Vertex Start,GraphPrt G);
void PrintPath(Vertex V,TablePrt T);
void PrintDist(Vertex v,TablePrt T);
void Dijkstra(Vertex Start,GraphPrt G,TablePrt T);
#endif