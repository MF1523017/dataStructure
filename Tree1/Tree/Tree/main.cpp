#include <iostream>
#include"tree.h"

using namespace std;

int main()
{
	int a[7]={7,2,4,1,3,5,6};
    SearchTree T=new TreeNode;
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
    cout << "Hello world!" << endl;
    return 0;
}
