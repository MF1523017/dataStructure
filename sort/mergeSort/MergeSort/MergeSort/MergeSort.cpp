// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
void print(vector<int> &nums)
{
	for (auto n : nums)
		cout << n << " ";
	cout << endl;
}
void merge(vector<int>&nums, vector<int> &tmp, int left, int mid, int right)
{
	int left_end, num_elements, tmp_pos;
	cout << "left " << left << " right " << right << ": ";
	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1;
	while ((left <= left_end) && (mid <= right))
	{
		if (nums[left] <= nums[mid])
			tmp[tmp_pos++] = nums[left++];
		else
			tmp[tmp_pos++] = nums[mid++];
	}
	while (left <= left_end)
		tmp[tmp_pos++] = nums[left++];
	while (mid <= right)
		tmp[tmp_pos++] = nums[mid++];
	
	for (int i = 0; i < num_elements; ++i,--right)
		nums[right] = tmp[right];
	print(nums);
}
void m_sort(vector<int> &nums, vector<int>&tmp, int left, int right)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		m_sort(nums, tmp, left, mid);
		m_sort(nums, tmp, mid+1, right);
		merge(nums, tmp, left, mid + 1, right);
	}
}
void merge_sort(vector<int> &nums)
{
	vector<int>tmp(nums.size(), 0);
	m_sort(nums, tmp, 0, nums.size()-1);
}


int main()
{
	vector<int> nums({ 3,2,5,4,6,7,1,8,9,0});
	merge_sort(nums);
	print(nums);
    return 0;
}

