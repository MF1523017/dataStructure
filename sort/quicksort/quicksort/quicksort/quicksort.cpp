#include"quicksort.h"
int partition(std::vector<int>&a, int left, int right, int pivotIndex)
{
	int pivotValue = a[pivotIndex];
	swap(a[pivotIndex], a[right]);//将基准元素放到最右边
	int storeIndex = left;
	for (int i = left; i < right; ++i)
	{
		if (a[i] < pivotValue)//将小于基准元素的放到左边，
		{
			swap(a[storeIndex], a[i]);//将当前元素交换到左边
			++storeIndex;
		}
	}
	swap(a[right], a[storeIndex]);//将基准元素放到分界位置
	return storeIndex;//返回分界点
}
void quicksort(std::vector<int> &a, int left, int right)
{
	if (right > left)
	{
		int pivotIndex = right;
		//获得分块边界
		int pivotNewIndex = partition(a, left, right, pivotIndex);
		quicksort(a, left, pivotNewIndex - 1);//排序左边
		quicksort(a, pivotNewIndex + 1, right);//排序右边
	}
}
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
