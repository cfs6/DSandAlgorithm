/*给出两个有序的整数数组A和B，请将数组B合并到数组A中，变成一个有序的数组 
注意： 
可以假设A数组有足够的空间存放B数组的元素，A和B中初始的元素数目分别为m和n */
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	static int compareFunc(const void * a, const void * b)
	{
		return (*(int*)a - *(int*)b);
	}

	void merge(int A[], int m, int B[], int n) {
		for (int i = 0; i < n; i++)
		{
			A[m + i] = B[i];
		}
		qsort(A, m + n, sizeof(int), compareFunc);
	}
};