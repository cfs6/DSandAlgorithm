/*���������������������A��B���뽫����B�ϲ�������A�У����һ����������� 
ע�⣺ 
���Լ���A�������㹻�Ŀռ���B�����Ԫ�أ�A��B�г�ʼ��Ԫ����Ŀ�ֱ�Ϊm��n */
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