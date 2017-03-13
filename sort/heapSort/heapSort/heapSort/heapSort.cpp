// heapSort.cpp : 定义控制台应用程序的入口点。
//堆排序

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using std::swap;
using std::vector;
using std::cout;
using std::endl;
void percDown(vector<int> &nums, int index,int heapSize)
{
	int leftChild, rightChild, maxIndex;

	while (true)
	{
		 leftChild = 2 * index + 1;
		 rightChild = leftChild + 1;
		 maxIndex = index;
		 if (leftChild < heapSize && nums[leftChild]>nums[maxIndex])
			 maxIndex = leftChild;
		 if (rightChild<heapSize && nums[rightChild]>nums[maxIndex])
			 maxIndex = rightChild;
		 if (maxIndex != index)
		 {
			 swap(nums[maxIndex], nums[index]);
			 index = maxIndex;
		 }
		 else
			 break;

	}
}
void heapSort(vector<int> &nums)
{
	//buildheap
	for (int i = nums.size() / 2; i >= 0; --i)
		percDown(nums, i,nums.size());
	//deleteMax
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		swap(nums[i], nums[0]);
		percDown(nums, 0,i);
	}
}
void print(vector<int> &nums)
{
	for (auto n : nums)
		cout << n << " ";
}
int main()
{
	vector<int>nums({ 9,2,5,6,3 });
	heapSort(nums);
	print(nums);
    return 0;
}

