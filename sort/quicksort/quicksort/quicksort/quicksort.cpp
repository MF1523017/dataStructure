#include"quicksort.h"
int partition(std::vector<int>&a, int left, int right, int pivotIndex)
{
	int pivotValue = a[pivotIndex];
	swap(a[pivotIndex], a[right]);//����׼Ԫ�طŵ����ұ�
	int storeIndex = left;
	for (int i = left; i < right; ++i)
	{
		if (a[i] < pivotValue)//��С�ڻ�׼Ԫ�صķŵ���ߣ�
		{
			swap(a[storeIndex], a[i]);//����ǰԪ�ؽ��������
			++storeIndex;
		}
	}
	swap(a[right], a[storeIndex]);//����׼Ԫ�طŵ��ֽ�λ��
	return storeIndex;//���طֽ��
}
void quicksort(std::vector<int> &a, int left, int right)
{
	if (right > left)
	{
		int pivotIndex = right;
		//��÷ֿ�߽�
		int pivotNewIndex = partition(a, left, right, pivotIndex);
		quicksort(a, left, pivotNewIndex - 1);//�������
		quicksort(a, pivotNewIndex + 1, right);//�����ұ�
	}
}
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
