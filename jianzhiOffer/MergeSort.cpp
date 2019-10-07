#include<iostream>
#include<vector>
using namespace std;

void mergesort(vector<int> &array,int low, int high){
	if (high - low < 2)
		return;
	int mid = (high - low) / 2;
	mergesort(array, low, mid);
	mergesort(array, mid, high);
	merge(array, low, mid, high);
}

void merge(vector<int> &array, int low, int mid, int high) {
	vector<int> res(high - low + 1);
	int i = low, j = mid;
	while (i <= mid&&j <= high) {
		if (array[i] <= array[j]) {
			res.push_back(array[i]);
			++i;
		}
		else {
			res.push_back(array[j]);
			++j;
		}
	}
	while(i > mid&&j<=high) {
		res.push_back(array[j]);
		++j;
	}
	while (j > high&&i <= mid) {
		res.push_back(array[i]);
		++i;
	}
	for (int i = low; i <= high; ++i) {
		int k = 0;
		array[i] = res[k];
		++k;
	}
}