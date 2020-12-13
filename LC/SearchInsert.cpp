/*给出一个有序的数组和一个目标值，如果数组中存在该目标值，则返回该目标值的下标。
如果数组中不存在该目标值，则返回如果将该目标值插入这个数组应该插入的位置的下标
假设数组中没有重复项。
下面给出几个样例：
[10,30,50,60], 50 → 2
[10,30,50,60], 20 → 1
[10,30,50,60], 70 → 4
[10,30,50,60], 0 → 0*/
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	注意数组首、尾位置
	*/
	int searchInsert(int A[], int n, int target) {
		if (n == 0)
			return 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == target)
				return i;
			else if (A[i] > target)
			{
				return i;
			}
		}
		return n;
	}
};


