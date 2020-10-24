/*����һ���Ǹ��������飬������������һ��Ԫ�ص�λ��
�����е�Ԫ�ش����������λ�ÿ�����Ծ����󳤶�
�ж����Ƿ��ܵ����������һ��Ԫ�ص�λ��
����
A =[2,3,1,1,4], ���� true.
A =[3,2,1,0,4], ���� false. */
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
	* @param A int����һά����
	* @param n int A���鳤��
	* @return bool������
	*/
	/*̰���㷨��ÿ�ζ��Ե�ǰλ��pos��Ԫ������A[pos]ǰ��������ǰλ��Ԫ��Ϊ0��
	��¼�µ�ǰ�ܴﵽ����Զ���룬��λ���һλ���ж�ÿ�Σ�����̰�ķ���ǰ����
	�Ƿ���Խ��֮ǰ����Զ���루λ��Ԫ��Ϊ0�ĵ㣩����λ�û�����0��-1����ʼ
	��һλ��Ԫ�ؼ�Ϊ0���򷵻�false
	*/
	bool canJump(int* A, int n) {
		int pos = 0;
		while (pos < (n - 1))
		{
			int step = A[pos];
			if (step == 0)
			{
				int farest = pos;
				while ((pos + A[pos]) <= farest)
				{
					--pos;
					if (pos <= 0)
						return false;
				}
				continue;
			}
			pos += step;
		}
		return true;
	}
};
