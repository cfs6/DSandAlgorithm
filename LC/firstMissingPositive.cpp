//不在数组里的最小正整数
/*给出一个无序的整数型数组，求不在给定数组里的最小的正整数
例如：
给出的数组为[1,2,0] 返回3,
给出的数组为[4,3,-1,-2,1] 返回2.
你需要给出时间复杂度在O(n)之内并且空间复杂度为常数级的算法*/
#include<math.h>
#include<cmath>
class Solution {
public:
	/*基于计数排序的思路。对0,1,2,...,n范围内的数把他放到对应的下标处。
	比如对于元素i放到下标i-1处，然后对数组从前往后遍历，
	找到第一个不匹配的，即是最小缺失正数。*/
	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i<n; i++)
		{
			int x = A[i];
			while (x>0 && x <= n && A[x - 1] != x)
				swap(x, A[x - 1]);
		}

		for (int i = 0; i<n; i++)
			if (A[i] != i + 1)
				return i + 1;

		return n + 1;
	}
};