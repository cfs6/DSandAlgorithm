/*����һ������������һ��Ŀ��ֵ����������д��ڸ�Ŀ��ֵ���򷵻ظ�Ŀ��ֵ���±ꡣ
��������в����ڸ�Ŀ��ֵ���򷵻��������Ŀ��ֵ�����������Ӧ�ò����λ�õ��±�
����������û���ظ��
�����������������
[10,30,50,60], 50 �� 2
[10,30,50,60], 20 �� 1
[10,30,50,60], 70 �� 4
[10,30,50,60], 0 �� 0*/
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	ע�������ס�βλ��
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


