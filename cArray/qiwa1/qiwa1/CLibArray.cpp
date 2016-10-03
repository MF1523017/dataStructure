//#include <stdio.h>
#include<cstring>
#include<stdlib.h>
#include "CLibArray.h"

void array_initial(CArray &array)
{
//	int a[10]={0};
  array.capacity=0;
  array.size=0;
  array.buff=NULL;
}

void array_recap(CArray &array, int n)
{
  int *buff=new int[n];
  memcpy(buff,array.buff,array.size*sizeof(int));
  delete []array.buff;
  array.capacity=n;
  array.buff=buff;
}

int array_capacity(CArray &array)
{
	return array.capacity;
}

void array_append(CArray &array, int i)
{
	while(array.capacity<i+1)
	{
		array_recap(array,(array.capacity*2));} 
      
	*(array.buff+i)=i;
     array.size=i+1; 
   
}

int array_size(CArray &array)
{
	return array.size;
}

//int array_at(CArray array, int i)
//{
//	i=*(array.buff+i);
//    return i;
//}


void array_copy(CArray &array, CArray &array2)
{  
   int i=0;   
   while(array2.capacity<array.capacity)
   { array_recap(array2,array.capacity);}
 
   for(i=0;i<array2.capacity;i++)
    {*(array2.buff+i)=*(array.buff+i);
   }
       array2.size=array.size;
}

bool array_compare(CArray &array, CArray &array2)
{
	bool flag;
	int k;
	if((array.capacity==array2.capacity)&&(array.size==array2.size))
	{
		flag=true;
		for (k=0;k<array.size;k++)
			{if(*(array.buff+k)!=*(array2.buff+k))
				{
						flag=false; 
						break;
				}
			}	     
	}
	else flag=false;
	return flag;
}


void array_insert (CArray &array, int i, int m)
{
	if (array.capacity<array.size+1)
		array_recap(array,2*array.capacity);
	//array_recap(array,21);
	for(int k=array.size;k>i;k--)
	{
	   *(array.buff+k)=*(array.buff+k-1);
	}
	*(array.buff+i)=m;
}


int& array_at(CArray &array, int i)
{
	return *(array.buff+i);
}

void array_destroy(CArray &array)
{
memset(&array, 0, sizeof(array));
}