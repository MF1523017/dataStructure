#ifndef AVLTREE_H
#define AVLTREE_H
struct AVLTreeNode;
typedef int ElementType ;
typedef struct AVLTreeNode* AVLTree ;
typedef AVLTree Position;
AVLTree MakeEmpty(AVLTree T);
AVLTree Find(AVLTree T,ElementType e);
AVLTree FindMin(AVLTree T);
AVLTree FindMax(AVLTree T);
AVLTree Insert(AVLTree T,ElementType e);
AVLTree Delete(AVLTree T,ElementType e);
void PrintTreeInOrder(AVLTree T);
void PrintTreePreOrder(AVLTree T);
void PrintTreePostOrder(AVLTree T);
struct AVLTreeNode
{
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
	int Height;
};

#endif // TREE_H
