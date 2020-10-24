//请实现函数 pow(x, n).
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	/**
	*
	* @param x double浮点型
	* @param n int
	* @return double浮点型
	*/
	//注意n可能为负数
	//iterately
	double pow(double x, int n) {
		double res = 1.0;
		double temp = x;
		for (int i = n; i != 0; i /= 2)
		{
			if (i % 2 != 0)
				res *= temp;
			temp *= temp;
		}
		return n > 0 ? res : 1 / res;
	}

	//recursively
	double pow(double x, int n)
	{
		if (x == 0)
			return 0;
		if (n >= 0)
			return power(x, n);
		if (n < 0)
			return 1 / power(x, -n);
	}

	double power(double x, int n)
	{
		if (n == 0)
			return 1;
		double half = power(x, n / 2);
		if (n % 2 == 0)
			return half*half;
		else
			return half*half*x;
	}
};

