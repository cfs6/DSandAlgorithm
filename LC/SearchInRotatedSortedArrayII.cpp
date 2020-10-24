/*继续思考题目 "Search in Rotated Sorted Array": 
如果数组种允许有重复元素怎么办？ 
会影响时间复杂度吗？是怎样影响时间复杂度的，为什么？
编写一个函数判断给定目标值是否在数组中。*/
#include<vector>
class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @param target int整型
	* @return bool布尔型
	*/
	bool search(int* A, int n, int target) {
		int start = 0;
		int end = n - 1;
		while (end >= start)
		{
			int mid = (end - start) / 2 + start;
			if (A[mid] == target)
				return true;
			if (A[start] == A[mid] && A[mid] == A[end])
			{
				start++;
				end--;
			}
			else if (A[start] < A[mid])
			{
				if (target == A[start])
					return true;
				if (target > A[start] && target < A[mid])
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			else if (A[mid]<A[end])
			{
				if (target == A[end])
					return true;
				if (target > A[mid] && target < A[end])
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
		}
		return false;
	}
};