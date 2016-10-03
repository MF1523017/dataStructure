#include "cArray.h"
void array_initial(CArray &A)
{
	A.buff=nullptr;
	A.size=0;
	A.capacity=0;
}
void checkArray(CArray &A,int cap)
{
	if (A.capacity<cap)
		array_recap(A,2*cap);
}
void array_recap(CArray &A,int cap)
{
	if (cap<=A.capacity)
		return;
	A.capacity=cap;
	ElementPrt buff=new ElementType[cap];
	A.size=A.size<A.capacity?A.size:A.capacity;
	for (int i=0;i<A.size;++i)
		buff[i]=A.buff[i];
	delete []A.buff; 
	A.buff=buff;
}
void array_append(CArray &A,ElementType e)
{
	checkArray(A,A.size+1);
	A.buff[A.size]=e;
	A.size+=1;
}
ElementType &array_at(CArray &A,int index)
{
	return A.buff[index];
}
void array_copy(CArray &src,CArray &dst)
{
	dst.size=src.size;
	dst.capacity=src.capacity;
	delete []dst.buff;
	dst.buff=new ElementType[src.capacity];
	for (int i=0;i<src.size;++i)
		dst.buff[i]=src.buff[i];
}
bool array_compare(CArray &src,CArray &dst)
{
	if (src.size!=dst.size || src.capacity!=dst.capacity)
		return false;
	for(int i=0;i<src.size;++i)
	{
		if (src.buff[i]!=dst.buff[i])
			return false;
	}
	return true;
}
void array_insert(CArray &A,int index,ElementType e)
{
	checkArray(A,A.size+1);
	for(int i=A.size;i>index;--i)
		A.buff[i]=A.buff[i-1];
	A.buff[index]=e;
}
void array_destroy(CArray &A)
{
	delete [] A.buff;
	A.capacity=0;
	A.size=0;
}