#include"hashSep.h"
#include<math.h>
bool isPrime(int n)
{
	if (n<3)
		return false;
	for (int i=2;i<sqrt((double)n);++i)
	{
		if (n%i==0)
			return false;
	}
	return true;
}

int nextPrime(int TableSize)
{
	while(TableSize)
	{
		if(isPrime(TableSize))
			break;
		TableSize+=1;
	}
	return TableSize;

}
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	H=new HashTbl;
	H->TableSize=nextPrime(TableSize);
	H->TheLists=new List[H->TableSize];
	for (int i=0;i<H->TableSize;++i)
	{
		H->TheLists[i]=new ListNode;
		H->TheLists[i]->Next=nullptr;
	}
	return H;
}
Position Find(ElementType key,HashTable H)
{
	Position P;
	List L=H->TheLists[hash(key,H->TableSize)];
	P=L->Next;
	while(P&&P->Element!=key)
		P=P->Next;
	return P;
}
void Insert(ElementType key,HashTable H)
{
	Position P=Find(key,H);
	if (P==nullptr)
	{
		List L=H->TheLists[hash(key,H->TableSize)];
		P=new ListNode;
		P->Element=key;
		P->Next=L->Next;
		L->Next=P;
	}
}
