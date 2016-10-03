#ifndef CARRAY_H
#define CARRAY_H
typedef int ElementType;
typedef ElementType * ElementPrt;
typedef struct 
{
	ElementPrt buff;
	int size;
	int capacity;
} CArray;

inline int array_capacity(CArray &A)
{
	return A.capacity;
}
inline int array_size(CArray &A)
{
	return A.size;
}
void array_initial(CArray &A);
void array_recap(CArray &A,int cap);
void array_append(CArray &A,ElementType e);
ElementType &array_at(CArray &A,int index);
void array_copy(CArray &src,CArray &dst);
bool array_compare(CArray &src,CArray &dst);
void array_insert(CArray &A,int index,ElementType e);
void array_destroy(CArray &A);
#endif