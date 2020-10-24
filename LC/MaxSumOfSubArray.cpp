/*
请计算给出的数组（至少含有一个数字）中具有最大和的子数组（子数组要求在原数组中连续）
例如：给出的数组为[−2,0,−3,4,−2,2,2,−5,4],
子数组[−2,0,−3,4,−2,2,2,−5,4],具有最大的和:6.
*/

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<memory>
using namespace std;

class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @return int整型
	*/
	/*
	*从头开始累加，直到和为负。此时前面这段不能给后面的串带来正收益，
	*应舍弃，sum清零然后在开始统计最大的sum.
	*/
	int maxSubArray(int* A, int n) {
		if (n == 0)
			return 0;
		int sum = 0, maxSum = A[0];
		for (int i = 0; i < n; ++i)
		{
			sum += A[i];
			if (maxSum < sum)
				maxSum = sum;
			if (sum < 0)
				sum = 0;
		}
		return maxSum;
	}
};