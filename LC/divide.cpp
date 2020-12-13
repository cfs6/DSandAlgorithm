/*在不使用乘法运算符，除法运算符和取余运算符的情况下对两个数进行相除操作*/
#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* 直接减遇到大数时容易超时，使用位移<<1(成倍加)来降低复杂度，需要注意符号
	*/
	int divide(int dividend, int divisor) {
		bool minus = false;
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		long long longDvidend = abs(dividend);
		long long longDivisor = abs(divisor);

		int count = 0;
		while (longDvidend >= longDivisor)
		{
			long long temp = longDivisor;
			int multiply = 1;
			while (longDvidend >= (temp << 1))
			{
				temp <<= 1;
				multiply <<= 1;
			}
			longDvidend -= temp;
			count += multiply;
		}
		count = (sign == 1) ? count : (-count);
		return count;
	}
};