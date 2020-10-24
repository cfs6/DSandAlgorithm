/*给出一个转动过的有序数组，你事先不知道该数组转动了多少
(例如,0 1 2 4 5 6 7可能变为4 5 6 7 0 1 2).
在数组中搜索给出的目标值，如果能在数组中找到，返回它的索引，否则返回-1。
假设数组中不存在重复项。*/
class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @param target int整型
	* @return int整型
	*/
	int search(int* A, int n, int target) {
		int first = 0;
		int last = n - 1;
		while (first <= last)
		{
			int mid = (last - first) / 2 + first;
			if (A[mid] == target)
				return mid;
			if (A[first] < A[mid])  //左侧有序,则在左侧进行二分查找
			{
				if (target >= A[first] && target < A[mid])
				{
					last = mid - 1;
				}
				else
				{
					first = mid + 1;
				}
			}
			else                    //右侧有序，则在右侧进行二分查找
			{
				if (target > A[mid] && target <= A[last])
				{
					first = mid + 1;
				}
				else
				{
					last = mid - 1;
				}
			}
		}
		return -1;
	}
};
