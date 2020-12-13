/*ʵ�ֺ���next permutation����һ�����У����������е������������г��ֵ����е���һ����������С�
�������е������������г��ֵ����е���һ����������С�
������������������У���������Ϊ�ֵ�����С�����У��������У�
��Ҫʹ��ԭ���㷨�����������⣬�������������ڴ�ռ�
�����л����������������������ݣ��ұ�������Ĵ�
1,2,3��1,3,2
3,2,1��1,2,3
1,1,5��1,5,1*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
	/*
	* 1.�Ӻ���ǰ�ҵ��������������ĵ�
	* 2.��������������ĵ�֤�������Ƿǵ����ģ�ֱ��reverse��Ȼ�󷵻ؼ���
	* 3.����ҵ������������е�7�������´Ӻ���ǰѰ�Ҵ���3�ĵ�һ��������5
	* 4.����3��5��λ�ã�Ȼ�󽫺���������������У����ɵõ����
	*/
public:
	void nextPermutation(vector<int> &num) {
		if (num.size() <= 1)
			return;
		int t = num.size() - 1;
		bool isMaxSorted = true;
		for (; t > 0; --t)
		{
			if (num[t] > num[t - 1])
			{
				isMaxSorted = false;
				break;
			}
		}
		if (isMaxSorted)
		{
			reverse(num.begin(), num.end());
			return;
		}
		int i = num.size() - 1;
		for (; i >= t; --i)
		{
			if (num[i] > num[t - 1])
			{
				swap(num[i], num[t - 1]);
				sort(num.begin() + t, num.end());
				return;
			}
		}
	}
};