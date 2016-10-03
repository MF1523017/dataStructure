#include"hashSep.h"
#include<iostream>
using std::cout;
using std::endl;
int main(int argc,char ** argv)
{
	HashTable H=InitializeTable(10);
	for(int i=0;i<20;i++)
		Insert(i,H);
	cout<<Find(12,H)->Element<<endl;
	cout<<H->TableSize<<endl;
	return 0;
}