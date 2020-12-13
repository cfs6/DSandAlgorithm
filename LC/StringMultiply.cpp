//字符串乘法
/*给出两个用字符串表示的数字，将两个数字的乘积作为字符串返回。
备注：数字可以无限大，且是非负数。*/
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
	/**
	*
	* @param num1 string字符串
	* @param num2 string字符串
	* @return string字符串
	*/
	string strAdd(string num1, string num2)
	{
		if (num1 == "")
			return num2;
		string res;
		bool carry = false;
		int num1Length = num1.length();
		int num2Length = num2.length();
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int i = 0;
		while (i < num1Length && i < num2Length)
		{
			int digit = (num1[i] - '0') + (num2[i] - '0');
			if (carry)
				++digit;
			if (digit >= 10)
			{
				carry = true;
				digit -= 10;
			}
			else
			{
				carry = false;
			}
			res += ('0' + digit);
			++i;
		}
		while (i < num1Length)
		{
			if (num1[i] == '9' && carry)
			{
				res += '0';
			}
			else if (num1[i] != '9' && carry)
			{
				int digit = num1[i] - '0';
				char ch = digit + 1 + '0';
				res += ch;
				carry = false;
			}
			else
			{
				res += num1[i];
				carry = false;
			}
			++i;
		}
		while (i < num2Length)
		{
			if (num2[i] == '9' && carry)
			{
				res += '0';
			}
			else if (num2[i] != '9' && carry)
			{
				int digit = num2[i] - '0';
				char ch = digit + 1 + '0';
				res += ch;
				carry = false;
			}
			else
			{
				res += num2[i];
				carry = false;
			}
			++i;
		}
		if (carry)
			res += '1';
		reverse(res.begin(), res.end());
		return res;
	}

	string multiplyOneDigit(string num1, char num2)
	{
		int num1Length = num1.length();
		int carry = 0;
		string result;
		int digit2 = num2 - '0';
		for (int i = num1Length - 1; i >= 0; --i)
		{
			int digit1 = num1[i] - '0';

			int res = digit1*digit2 + carry;
			if (res >= 10)
			{
				carry = res / 10;
				res %= 10;
				digit1 = res;
			}
			else
			{
				digit1 = res;
				carry = 0;
			}
			char ch = '0' + digit1;
			result += ch;
		}
		if (carry)
			result += ('0' + carry);
		reverse(result.begin(), result.end());
		return result;
	}

	string multiply(string num1, string num2) {
		string res;
		string result;
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}
		int num1Length = num1.length();
		int num2Length = num2.length();

		for (int i = num2Length - 1, k = 0; i >= 0; --i, ++k)
		{
			char ch2 = num2[i];
			res = multiplyOneDigit(num1, ch2);
			int k2 = 0;
			while (k2 != k)
			{
				res += '0';
				++k2;
			}
			result = strAdd(result, res);
		}
		return result;
	}
};