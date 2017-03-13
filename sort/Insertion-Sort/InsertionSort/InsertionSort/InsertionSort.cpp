// InsertionSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
int binarySearch(vector<int> &nums, int left, int right,int newValue)
{
	while (left != right)
	{
		int mid= (left + right) / 2;
		if (nums[mid] < newValue)
		{
			right = mid;
		}
		else if (nums[mid] > newValue)
		{
			left = mid;
		}
		else
			return mid;
	}
	return left;
}
void InsertionSort(vector<int> &nums)
{
	int k;
	for (int i = 1; i < nums.size(); ++i)
	{
		int newValue = nums[i];
		
		////直接遍历查找
		//int j = i - 1;
		//for (; j >= 0; j--)//查找到比新元素小的位置
		//{
		//	if (nums[j] < newValue)
		//		break;
		//}
		////二分查找
		////int j = binarySearch(nums, 0, i - 1, newValue);
		//int k = i;
		//for (; k > j+1; --k)//一步一步往后移动，将新元素插入其中
		//{
		//	nums[k] = nums[k - 1];
		//}
		for (k = i; k > 0 && nums[k - 1] > newValue; --k)
			nums[k] = nums[k - 1];
		nums[k] = newValue;
	}
}
void print(vector<int> &nums)
{
	for (auto n : nums)
		std::cout << n << " ";
}
int main()
{
	vector<int> nums({ 5, 6, 3, 1, 8, 7, 2, 4 });
	InsertionSort(nums);
	print(nums);
    return 0;
}

