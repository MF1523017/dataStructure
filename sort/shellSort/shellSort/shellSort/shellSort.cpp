// shellSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
//如果是有序的，复杂度为O(n);
void shellSort(vector<int>&nums)
{
	int k;
	for (int increment = nums.size() / 2; increment > 0; increment /= 2)
	{
		for (int j = increment; j < nums.size(); ++j)
		{
			int tmp = nums[j];
			for (k = j; k >= increment; k -= increment)
			{
				if (tmp < nums[k - increment])
					nums[k] = nums[k - increment];
				else
					break;
			}
			nums[k] = tmp;
		}
	}
}

void print(vector<int> &nums)
{
	for (auto n : nums)
		cout << n << " ";
}
int main(int argc,char *argv[])
{
	vector<int> nums({ 80, 93, 60, 12, 42, 30, 68, 85, 10 });
	shellSort(nums);
	print(nums);
    return 0;
}

