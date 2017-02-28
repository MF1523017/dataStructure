// BubbleSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
void bubbleSort(vector<int> &nums)
{
	int numSize = nums.size();
	for (int i = numSize-1; i >0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
}
void print(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		std::cout << nums[i] << " ";
	}
}
int main(int argc,char *argv[])
{
	vector<int> nums({ 5,3,2,1,6,0 });
	bubbleSort(nums);
	print(nums);
    return 0;
}

