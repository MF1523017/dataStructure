#ifndef PRIM_H
#define PRIM_H
#include"graph.h"
//PrimTableEntry info: the header point to nearest neighbors
//					Known records whether the Vertex is known or not; 
//					Dist update the distance of the Vertex to other Vertexes;
//					Path records the last Vertex;
struct PrimTableEntry
{
	List Header;
	bool Known;
	int Dist;
	Vertex Path;
};

typedef struct PrimTableEntry * PrimTable;
typedef PrimTable * PrimTablePrt;
PrimTablePrt InitPrimTable(Vertex Start, GraphPrt G);
void PrintTreeValue(GraphPrt G, PrimTablePrt T);
void PrintTreeEdge(GraphPrt G, PrimTablePrt T);
void Prim(Vertex Start, GraphPrt G, PrimTablePrt T);
#endif