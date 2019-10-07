//FindNumInSortedArray
//统计数字在排序数组中出现的次数
//基于二分查找
//分别找到第一个和最后一个k
#include<iostream>
using namespace std;

int GetFirstK(int* array, int length, int k, int start, int end) {    
	if (start>end) {
		return -1;
	}
	int mid = (end - start) / 2;
	int middata = array[mid];
	int firstK;
	if (middata > k) {
		firstK = GetFirstK(array, length, k, start, mid-1);
	}
	else if (middata < k) {
		firstK = GetFirstK(array, length, k, mid + 1, end);
	}
	else {
		if (array[mid - 1] = k) {
			firstK = GetFirstK(array, length, k, start, mid - 1);
		}
		else
			firstK = mid;
	}
	return firstK;
}

int GetLastK(int* array, int length, int k, int start, int end) {
	if (start > end)
		return -1;
	int mid = (start - end) / 2;
	int middata = array[mid];
	if (middata == k) {
		if (array[mid + 1] == k) {
			start = mid + 1;
		}
		else
			return mid;
	}
	else if (middata > k) {
		end = mid - 1;
	}
	else
		start = mid + 1;

	return GetLastK(array, length, k, start, end);
}


int GetNumberOfK(int* array, int length, int k) {
	if (array == nullptr)
		return 0;
	int start = 0;
	int end = length - 1;
	int firstK = GetFirstK(array, length, k, start, end);
	int lastK = GetLastK(array, length, k, start, end);
	int count;
	if(firstK>-1&&lastK>-1)
		count = lastK - firstK + 1;
	return count;
}

