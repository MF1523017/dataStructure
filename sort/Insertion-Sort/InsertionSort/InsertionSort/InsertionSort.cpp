// InsertionSort.cpp : �������̨Ӧ�ó������ڵ㡣
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
		
		////ֱ�ӱ�������
		//int j = i - 1;
		//for (; j >= 0; j--)//���ҵ�����Ԫ��С��λ��
		//{
		//	if (nums[j] < newValue)
		//		break;
		//}
		////���ֲ���
		////int j = binarySearch(nums, 0, i - 1, newValue);
		//int k = i;
		//for (; k > j+1; --k)//һ��һ�������ƶ�������Ԫ�ز�������
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

