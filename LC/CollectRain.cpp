//收集雨水
/*给出n个数字，表示一个高程图，高程图中每一条的宽度为1，请计算下雨之后这个地形可以存储多少水
例如
给出[0,1,0,2,1,0,1,3,2,1,2,1],返回6.*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @return int整型
	*/
	int trap(int A[], int n) {
		if (n == 0)
			return 0;
		//找到最大值下标
		int highestPos=0;
		int height = A[0];
		for (int i = 0; i < n; ++i)
		{
			if (A[i] > height)
			{
				height = A[i];
				highestPos = i;
			}
		}
		int sum = 0;
		int left = 0, right = 0;
		//计算左边的容量
		for (int i = 0; i < highestPos; ++i)
		{
			if (left < A[i])
				left = A[i];
			else
			{
				sum += left - A[i];
			}
		}
		//计算右边的容量
		for (int i = n-1; i >highestPos; --i)
		{
			if (right < A[i])
				right = A[i];
			else
			{
				sum += right - A[i];
			}
		}
		return sum;
	}
};