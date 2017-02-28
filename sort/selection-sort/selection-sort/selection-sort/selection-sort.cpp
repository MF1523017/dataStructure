// selection-sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
void print(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		std::cout << nums[i] << " ";
	}
}
void selectionSort(vector<int> &nums)
{
	int minIndex = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		minIndex = i;
		for (int j = i; j < nums.size(); ++j)
		{
			if (nums[j] < nums[minIndex])
			{
				minIndex = j;
			}
		}
		int tmp = nums[minIndex];
		nums[minIndex] = nums[i];
		nums[i] = tmp;
	}
}

int main()
{
	vector<int> nums({ 8, 5, 2, 6, 9, 3, 1, 4, 0, 7 });
	selectionSort(nums);
	print(nums);
    return 0;
}

