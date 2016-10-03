#include"avltree.h"
#include<iostream>
//二叉查找树，左子树永远小于右子树，
static int Height(Position p)
{
	if(p==nullptr)
		return -1;
	else
		return p->Height;
}
AVLTree MakeEmpty(AVLTree T)
{
    if (T!=nullptr)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        delete T;
    }
	return T;
}
AVLTree Find(AVLTree T,ElementType e)
{
    if (T==nullptr)
        return T;
    if (e<T->Element)
        return Find(T->Left,e);
    else if(e>T->Element)
        return Find(T->Right,e);
    else
        return T;
}
AVLTree FindMin(AVLTree T)
{
    if (T==nullptr)
        return T;
    else if (T->Left==nullptr)
        return T;
    else
        return FindMin(T->Left);
}
AVLTree FindMax(AVLTree T)
{
    if (T==nullptr)
        return T;
    else if (T->Right==nullptr)
        return T;
    else
        return FindMax(T->Right);
}
static int Max(int a,int b)
{
	return a>b?a:b;
}
static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1=K2->Right;
	K2->Right=K1->Left;
	K1->Left=K2;
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	return K1;
}
static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	return K1;
}
static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}
static Position DoubleRotateWithRight(Position K3)
{
	K3->Right=SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);	
}
AVLTree Insert(AVLTree T,ElementType e)
{
    if (T==nullptr){
        T=new AVLTreeNode;
        T->Element=e;
        T->Left=T->Right=nullptr;
		T->Height=0;
        }
    if (e<T->Element){
        T->Left=Insert(T->Left,e);
		if(Height(T->Left)-Height(T->Right)==2){
			if(e<T->Left->Element)
				T=SingleRotateWithLeft(T);
			else
				T=DoubleRotateWithLeft(T);
		}	
	}
	else if(e>T->Element){
        T->Right=Insert(T->Right,e);
		if(Height(T->Right)-Height(T->Left)==2){
			if(e<T->Left->Element)
				T=SingleRotateWithRight(T);
			else
				T=DoubleRotateWithRight(T);
		}	
	}
	T->Height=Max(Height(T->Left),Height(T->Right))+1;
    return T;
}

void PrintTreePostOrder(AVLTree T)
{
	if(T!=nullptr)
	{
		PrintTreePostOrder(T->Left);
		PrintTreePostOrder(T->Right);
		std::cout<<T->Element<<" ";
	}
}
void PrintTreePreOrder(AVLTree T)
{
	if(T!=nullptr)
	{
		std::cout<<T->Element<<" ";
		PrintTreePreOrder(T->Left);
		PrintTreePreOrder(T->Right);
		
	}
}
void PrintTreeInOrder(AVLTree T)
{
	if(T!=nullptr)
	{
		PrintTreeInOrder(T->Left);
		std::cout<<T->Element<<" ";
		PrintTreeInOrder(T->Right);
	}
}


#if 0
AVLTree Delete(AVLTree T,ElementType e)
{
	Position tmp;
	if (T==nullptr)
		return T;
	else if(e<T->Element)
		T->Left=Delete(T->Left,e);
	else if (e>T->Element)
		T->Right=Delete(T->Right,e);
	else if(T->Left&&T->Right)
	{
		tmp=FindMin(T->Right);
		T->Element=tmp->Element;
		T->Right=Delete(T->Right,tmp->Element);
	}
	else
	{
		tmp=T;
		if (T->Left==nullptr)
			T=T->Right;
		else if(T->Right==nullptr)
			T=T->Left;
		delete tmp;
	}
	return T;

}

#endif