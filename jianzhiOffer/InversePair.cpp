//统计数组中的逆序对
#include<iostream>
#include<vector>
using namespace std;

int InversePair(int* array, int length) {
	if (array == nullptr)
		return 0;
	int start = 0;
	int end = length - 1;
	int* copy = new int[length];
	for (int i = 0; i < length - 1; ++i)
		copy[i] = array[i];
	int count = InversePairCore(array, copy, start, end);
	return count;
}

int InversePairCore(int* array, int *copy, int start, int end) {
	if (start == end) {
		copy[start] = array[start];
		return 0;
	}
	int length = end - start/2;
	
	int left = InversePairCore(array, copy, start, start + length);
	int right = InversePairCore(array, copy, start + length, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start&&j >= start + length + 1) {
		if (array[i] > array[j]) {
			copy[indexCopy--] = array[i--];
			count += j - start - length;
		}
		else
			copy[indexCopy--] = array[j--];
	}
	for (; i >= start; --i) {
		copy[indexCopy--] = array[i];
	}
	for (; j >= start + length; --j) {
		copy[indexCopy--] = array[j];
	}
	return left + right + count;

}

