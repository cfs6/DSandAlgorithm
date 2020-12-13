//�ռ���ˮ
/*����n�����֣���ʾһ���߳�ͼ���߳�ͼ��ÿһ���Ŀ��Ϊ1�����������֮��������ο��Դ洢����ˮ
����
����[0,1,0,2,1,0,1,3,2,1,2,1],����6.*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param A int����һά����
	* @param n int A���鳤��
	* @return int����
	*/
	int trap(int A[], int n) {
		if (n == 0)
			return 0;
		//�ҵ����ֵ�±�
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
		//������ߵ�����
		for (int i = 0; i < highestPos; ++i)
		{
			if (left < A[i])
				left = A[i];
			else
			{
				sum += left - A[i];
			}
		}
		//�����ұߵ�����
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