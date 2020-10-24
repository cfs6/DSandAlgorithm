/*����˼����Ŀ "Search in Rotated Sorted Array": 
����������������ظ�Ԫ����ô�죿 
��Ӱ��ʱ�临�Ӷ���������Ӱ��ʱ�临�Ӷȵģ�Ϊʲô��
��дһ�������жϸ���Ŀ��ֵ�Ƿ��������С�*/
#include<vector>
class Solution {
public:
	/**
	*
	* @param A int����һά����
	* @param n int A���鳤��
	* @param target int����
	* @return bool������
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