#ifndef HASHSEP_H
#define HASHSEP_H
struct ListNode;
typedef struct ListNode * Position;
typedef Position List;
typedef List * ListPrt;
struct HashTbl;
typedef struct HashTbl * HashTable;
typedef int ElementType;

struct ListNode
{
	ElementType Element;
	List Next;
};
struct HashTbl
{
	int TableSize;
	ListPrt TheLists;
};
inline int hash(ElementType key,int tableSize)
{
	return key %tableSize;
}
HashTable InitializeTable(int TableSize);
Position Find(ElementType key,HashTable H);
void Insert(ElementType key,HashTable H);

#endif