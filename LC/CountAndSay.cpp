/*外观数列的前几项如下：
1, 11, 21, 1211, 111221, ...
1读作“1个1”或11
11读作“2个1“或者21
21读作”1个2，1个1“或者1211
给出一个整数n，请给出序列的第n项
每一次读都是以前一次为基础
注意：序列中的数字用字符串表示*/
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int整型
	* @return string字符串
	*/
	//使用count保存连续相同的数字个数， 注意倒数第二个数字和最后一个数字
	string result;
	string res;
	string countAndSay(int n) {
		res = "1";
		if (n == 1)
			return res;
		res = "11";
		if (n == 2)
			return res;
		for (int i = 3; i <= n; ++i)
		{
			int count = 1;
			result.clear();
			for (int k = 0; k < res.size() - 1; ++k)
			{
				if (res[k] == res[k + 1])
				{
					count++;
					if ((k + 1) == (res.size() - 1))
					{
						result += ('0' + count);
						result += res[k];
					}
				}
				else if (res[k] != res[k + 1])
				{
					result += ('0' + count);
					result += res[k];
					if ((k + 1) == (res.size() - 1))
					{
						result += '1';
						result += res[k + 1];
					}
					count = 1;
				}
			}
			res.clear();
			res = result;
		}
		return result;
	}
};


