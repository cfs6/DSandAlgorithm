//word break
/*
给定一个字符串s和一组单词dict，
判断s是否可以用空格分割成一个单词序列，
使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
*/
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
	//dp数组 标志s[0-i]是否可划分为dict中的子串
	bool match(string str, unordered_set<string> &dict)
	{
		if (dict.find(str) != dict.end())
			return true;
		return false;
	}
	bool wordBreak(string s, unordered_set<string> &dict) {
		if ( s.length()==0 || dict.size() == 0)
			return false;
		int strlen = s.length();
		vector<bool> dp(strlen + 1, false);
		dp[0] = true;
		for (int i = 0; i < strlen; ++i)
		{
			for (int j = i; dp[i] && j < strlen; ++j)
			{
				if (match(s.substr(i, j - i + 1), dict))
				{
					dp[j+1] = true;
				}
			}
		}
		return dp[strlen];
	}
};