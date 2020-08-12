/*
给定一个字符串s和一组单词dict，在s中添加空格将s变成一个句子，
使得句子中的每一个单词都是dict中的单词 ,返回所有可能的结果
例如：给定的字符串s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
返回的结果为["cats and dog", "cat sand dog"].
*/
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
	vector<bool> *dp;
	vector<string> mystring;
	vector<string> result;
public:

	bool match(string s, unordered_set<string> &dict)
	{
		if (dict.find(s) != dict.end())
			return true;
		return false;
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int strlen = s.length();
		int dictsize = dict.size();

		if (strlen == 0 || dictsize == 0)
			return result;
		dp = new vector<bool>[s.size()];

		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i;  j < s.size(); j++)
			{
				dp[i].push_back(match(s.substr(i, j - i + 1), dict));
			}
		}
		handleStr(s.size() - 1, s);
		return result;
	}

	void handleStr(int i, string s)
	{
		if (i == -1)
		{
			string str;
			for (int j = mystring.size() - 1; j >= 0; j--)
			{
				str += mystring[j];
				if (j != 0)
					str += " ";
			}
			result.push_back(str);
		}
		else
		{
			for (int k = 0; k <= i; ++k)
			{
				if (dp[k][i - k])
				{
					mystring.push_back(s.substr(k, i - k + 1));
					handleStr(k - 1, s);
					mystring.pop_back();
				}
			}
		}
	}
};