#include"avltree.h"
#include<iostream>
int main()
{
	int a[7]={7,2,4,1,3,5,6};
    AVLTree T=new AVLTreeNode;
	T=nullptr;
    MakeEmpty(T);
    for (auto i: a)
        T=Insert(T,i);
	//Delete(T,4);
	PrintTreePreOrder(T);
	std::cout<<std::endl;
	PrintTreeInOrder(T);
	std::cout<<std::endl;
	PrintTreePostOrder(T);
	std::cout<<std::endl;
	MakeEmpty(T);
    return 0;
}
