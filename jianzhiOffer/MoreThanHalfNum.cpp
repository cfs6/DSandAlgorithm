//Find a number appear more than half times in  the array
#include<cstdlib>
int MoreThanHalfNum(int* numbers, int length) {
	if (numbers == nullptr || length <= 0)
		return 0;
	int res = NewPartition(numbers, 0, length - 1, length);
	return res;
}

int NewPartition(int* numbers, int low, int high, int length) {
	int p = rand() % length;
	int nLow = low;
	int temp = numbers[p];
	numbers[p] = numbers[0];
	numbers[0] = temp;
//	int pivot = numbers[0];
	while (nLow < high) {
		while (numbers[high] > numbers[p] && (high > nLow))
			high--;
		numbers[p] = numbers[high];
		while (numbers[nLow] < numbers[p] && (high > nLow))
			nLow++;
		numbers[high] = numbers[nLow];
	}
	numbers[nLow] = numbers[p];
	
	if (nLow == length / 2)
		return numbers[nLow];
	else if (nLow < length / 2) {
		return NewPartition(numbers, nLow+1, high, high - nLow + 1);
	}
	else if (nLow > length / 2) {
		return NewPartition(numbers, low, nLow-1, nLow - low + 1);
	}
}

