/*给出两个用字符串表示的二进制数，返回他们的和（也用字符串表示） 
例如： 
a ="11"
b ="1"
返回"100".*/
#include<string>
using namespace std;
class Solution {
public:
	/**
	*
	* @param a string字符串
	* @param b string字符串
	* @return string字符串
	*/
	//先转为十进制相加后转回二进制，会超内存
	long long binaryToDecimal(string str)
	{
		int strSize = str.size();
		long long dec = 0, k = 0;
		for (int i = strSize - 1; i >= 0; k++, i--)
		{
			if (str[i] == '1')
			{
				dec += pow(2, k);
			}
		}
		return dec;
	}

	string decimalToBinary(long long num)
	{
		if (num == 0)
			return "0";
		string bin;
		int temp;
		while (num != 0)
		{
			temp = num % 2;
			if (temp)
				bin += "1";
			else
				bin += "0";

			num /= 2;
		}
		reverse(bin.begin(), bin.end());
		return bin;
	}

	string addBinary(string a, string b) {
		long long num1 = binaryToDecimal(a);
		long long num2 = binaryToDecimal(b);
		long long res = num1 + num2;
		string resStr = decimalToBinary(res);
		return resStr;
	}



	//直接对位相加方法
	string addBinary(string a, string b)
	{
		int straLength = a.length();
		int strbLength = b.length();
		string res;
		int i, j;
		bool carry = false;
		for (i = straLength - 1, j = strbLength - 1; i >= 0 && j >= 0; --i, --j)
		{
			//			cout << a[i] << endl;
			//			cout << b[i] << endl;
			if (carry)
			{
				if (a[i] == '1' && b[j] == '1')
				{
					res += "1";
				}
				else if (a[i] == '1' && b[j] == '0')
				{
					res += "0";
				}
				else if (a[i] == '0' && b[j] == '1')
				{
					res += "0";
				}
				else
				{
					res += "1";
					carry = false;
				}
			}
			else
			{
				if (a[i] == '1' && b[j] == '1')
				{
					res += "0";
					carry = true;
				}
				else if (a[i] == '1' && b[j] == '0')
				{
					res += "1";
				}
				else if (a[i] == '0' && b[j] == '1')
				{
					res += "1";
				}
				else
				{
					res += "0";
				}
			}
		}
		while (i >= 0)
		{
			if (carry)
			{
				if (a[i] == '1')
				{
					res += '0';
				}
				else
				{
					res += '1';
					carry = false;
				}
				--i;
			}
			else
			{
				res += a[i];
				--i;
			}
		}
		while (j >= 0)
		{
			if (carry)
			{
				if (b[j] == '1')
				{
					res += '0';
				}
				else
				{
					res += '1';
					carry = false;
				}
				--j;
			}
			else
			{
				res += b[j];
				--j;
			}
		}
		if (carry)
		{
			res += '1';
		}
		reverse(res.begin(), res.end());
		return res;
	}


};