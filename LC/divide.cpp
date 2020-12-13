/*�ڲ�ʹ�ó˷�������������������ȡ�������������¶������������������*/
#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* ֱ�Ӽ���������ʱ���׳�ʱ��ʹ��λ��<<1(�ɱ���)�����͸��Ӷȣ���Ҫע�����
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