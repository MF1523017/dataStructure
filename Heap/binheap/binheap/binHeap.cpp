#include"binHeap.h"

PriorityQueue Initialize(int maxElements)
{
	PriorityQueue H = new HeapStruct;
	H->Elements = new ElementType[maxElements];//开辟一段连续的堆空间存储数据
	H->Capacity = maxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	return H;
}
void Destory(PriorityQueue H)
{
	delete[] H->Elements;
	delete H;
}
void MakeEmpty(PriorityQueue H)
{
	H->Size = 0;
}
void Insert(ElementType x, PriorityQueue H)
{
	if (isFull(H)) 
		return;
	int i;
	for (i = ++H->Size; H->Elements[i / 2] > x; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = x;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i, child;
	ElementType minElement, lastElement;
	if (IsEmpty(H))
		return H->Elements[0];
	minElement = H->Elements[1];
	lastElement = H->Elements[H->Size--];
	for (i = 1; i * 2 <= H->Size; i = child)
	{
		child = i * 2;
		if (child != H->Size&&H->Elements[child + 1] < H->Elements[child])//右儿子小于左儿子，转到右子树
			child++;
		if (lastElement > H->Elements[child])
			H->Elements[i] = H->Elements[child];
		else
			break;
	}
	H->Elements[i] = lastElement;
	return minElement;

}
ElementType FindMin(PriorityQueue H)
{
	return H->Elements[1];
}
bool IsEmpty(PriorityQueue H)
{
	return H->Size==0;
}
bool isFull(PriorityQueue H)
{
	return H->Size == H->Capacity;
}