/*����һ���������飬�����������ҳ�Ŀ��ֵ����ʼλ�úͽ���λ��
����㷨��ʱ�临�Ӷ�Ӧ����O(log n)֮��
��������в�����Ŀ�꣬����[-1, -1].
���磺
������������[50, 70, 70, 80, 80, 100]��Ŀ��ֵ��80,
����[3, 4].*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	//ʹ�ö��ֲ��ң��������ұ߽缴��,�ֱ��������ҼбƵõ����ұ߽�
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
				begin = mid + 1;     //��begin = mid �������ѭ��
			else
				end = mid - 1;       //��end = mid �������ѭ��
		}

		int begin2 = 0, end2 = n - 1;
		int mid2;
		while (begin2 <= end2)      //ע�⼫��λ��
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



