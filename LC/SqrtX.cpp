/*ʵ�ֺ��� int sqrt(int x).
���㲢����x��ƽ���� */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* @param x int����
	* @return int����
	*/
	/*ע��ʹ��int�ᳬ�����ޣ�Ӧʹ��long long*/
	int sqrt(int x) {
		if (x == 1)
			return 1;
		long long begin = 0, end = x;
		while (end - 1 > begin)
		{
			long long mid = begin + (end - begin) / 2;
			if (mid*mid == x)
				return mid;
			if ((mid*mid) > x)
			{
				end = mid;
			}
			else if ((mid*mid) < x)
			{
				begin = mid;
			}
		}
		return begin;
	}
};