/*题目描述
格雷码是一种二进制编码系统，如果任意两个相邻的代码只有一位二进制数不同，
则称这种编码为格雷码（Gray Code）。
给定一个非负整数n，表示代码的位数，打印格雷码的序列。格雷码序列必须以0开头。
例如：给定n=2，返回[0,1,3,2]. 格雷码的序列为： 
00 - 0↵01 - 1↵11 - 3↵10 - 2*/
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int整型
	* @return int整型vector
	*/
	vector<int> grayCode(int n) {
		int num;
		num = n << 1;
		vector<int> res;
		for (int i = 0; i < num; ++i)
		{
			res.push_back(i >> 1 ^ i);
		}
		return res;
	}
};