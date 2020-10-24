/*实现函数 int sqrt(int x).
计算并返回x的平方根 */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* @param x int整型
	* @return int整型
	*/
	/*注意使用int会超出上限，应使用long long*/
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