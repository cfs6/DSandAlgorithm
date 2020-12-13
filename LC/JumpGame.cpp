//��Ծ��ϷII
/*����һ���Ǹ��������飬������������һ��Ԫ�ص�λ��
�����е�Ԫ�ش����������λ�ÿ�����Ծ����󳤶�
���Ŀ���������ٵ���Ծ������������������һ��Ԫ�ص�λ��
����
�������� A =[2,3,1,1,4]
������Ҫ���β�����Ծ���������һ��Ԫ�ص�λ�á�
���������±�Ϊ0��λ��������1�����±�1��λ�ã�
Ȼ��������3���������һ��Ԫ�ص�λ�ã� */
#include<vector>
#include<string>
#include<iostream>
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


	int jump(int* A, int n) {
		int jumps = 0, curEnd = 0, curFurthest = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			curFurthest = max(curFurthest, i + A[i]);
			if (i == curEnd)
			{
				jumps++;
				curEnd = curFurthest;
			}
		}
		return jumps;
	}
};