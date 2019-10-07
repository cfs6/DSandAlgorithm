//Get the smallest numbers in the array
//Heap sort
//Max Heap
#include<vector>
#include<iostream>


std::vector<int> GetSmallestKNumbers(std::vector<int> array, int k) {
	std::vector<int> resHeap = BuildHeap(array, k-1);
	int arrayLength = array.size();
	for (int i = k; i < arrayLength; ++i) {
		if (array[i] < getMax(resHeap)) {
			resHeap[0] = array[i];
			percolateDown(array, 0);
		}
	}
	return resHeap;
}

std::vector<int> BuildHeap(std::vector<int> array, int n) {
	std::vector<int> pHeap(n);
	for (int i = 0; i < n; ++i) {
		pHeap[i] = array[i];
		percolatUP(pHeap, i);
	}
	return pHeap;
}

void percolatUP(std::vector<int> &array, int n) {// n为末元素
	while (((n - 1) >> 1) >= 0) {
		int parent = (n - 1) >> 1;
		if (array[n] < array[parent])
			break;
		int temp = array[n];
		array[n] = array[parent];
		array[parent] = temp;
		n = parent;
	}
}
void percolateDown(std::vector<int> &array, int n) {//从堆顶开始下滤n为堆顶元素 即n=0 
	int child1, child2;
	if ((-1 < (2 * n + 1)) && ((2 * n + 1) < n))
		child1 = 2 * n + 1;
	if ((-1 < (2 * n + 2)) && ((2 * n + 2) < n))
		child2 = 2 * n + 2;
	int maxIn3 = array[n] > array[child1] ? (array[n] > array[child2] ? n : child2) : (array[child1] > array[child2] ? child1 : child2);
	if (maxIn3 != n) {
		int temp = array[n];
		array[n] = array[maxIn3];
		array[maxIn3] = temp;
	}
	else
		return;
	percolateDown(array, maxIn3);
	
}
int getMax(std::vector<int> array) {
	return array[0];
}