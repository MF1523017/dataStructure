#pragma once
#define MinData (-32767)
struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
typedef int ElementType;
PriorityQueue Initialize(int maxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType x, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
bool IsEmpty(PriorityQueue H);
bool isFull(PriorityQueue H);

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};
