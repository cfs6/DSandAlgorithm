/*给出一个有序数组，请在数组中找出目标值的起始位置和结束位置
你的算法的时间复杂度应该在O(log n)之内
如果数组中不存在目标，返回[-1, -1].
例如：
给出的数组是[50, 70, 70, 80, 80, 100]，目标值是80,
返回[3, 4].*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	//使用二分查找，查找左右边界即可,分别向左、向右夹逼得到左右边界
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> res(2, -1);
		if (A == nullptr || n <= 0)
			return res;
		if (A[0] > target || A[n - 1] < target)
			return res;

		int begin = 0, end = n - 1;
		int mid;
		while (begin <= end)
		{
			mid = (end + begin) / 2;
			if (A[mid] < target)
				begin = mid + 1;     //若begin = mid 则可能死循环
			else
				end = mid - 1;       //若end = mid 则可能死循环
		}

		int begin2 = 0, end2 = n - 1;
		int mid2;
		while (begin2 <= end2)      //注意极限位置
		{
			mid2 = (end2 + begin2) / 2;
			if (A[mid2] <= target)
				begin2 = mid2 + 1;
			else
				end2 = mid2 - 1;
		}
		if (begin <= end2)
		{
			res[0] = begin;
			res[1] = end2;
		}
		return res;
	}
};



