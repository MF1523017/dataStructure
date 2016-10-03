#include <stdio.h>

typedef struct a{
	int * buff;
	int size;       //实际的大小
	int capacity;  //定义的大小
}CArray;

void array_initial(CArray &array);
void array_recap(CArray &array, int n);
int array_capacity(CArray &array);

void array_append(CArray &array, int i);
int array_size(CArray &array);
//int array_at(CArray array, int i);
void array_copy(CArray &array, CArray &array2);
bool array_compare(CArray &array, CArray &array2);
void array_insert (CArray &array, int i, int m);
int& array_at(CArray &array, int i);      
void array_destroy(CArray &array);



