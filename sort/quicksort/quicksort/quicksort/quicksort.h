#pragma once
#include<iostream>
#include<vector>
int partition(std::vector<int>&a, int left, int right, int pivotIndex);
void swap(int &a, int &b);
void quicksort(std::vector<int> &a, int left, int right);