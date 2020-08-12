/*给定一个字符串s，分割s使得s的每一个子串都是回文串 
返回所有的回文分割结果。（注意：返回结果的顺序需要和输入字符串中的字母顺序一致。） */
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param s string字符串
	* @return string字符串vector<vector<>>
	*/
	//dfs遍历并将满足回文要求的字符串加入result
	vector<string> strVec;
	vector<vector<string>> result;
	bool isPalindrome(string s) {        //以反向迭代器判断是否为回文串
		return s == string(s.rbegin(), s.rend());
	}
	void dfs(string s)
	{
		if (s == "")
		{
			result.push_back(strVec);
			return;
		}
		else
		{
			for (int i = 1; i <= s.size(); ++i)
			{
				if (isPalindrome(s.substr(0, i)))
				{
					strVec.push_back(s.substr(0, i));
					dfs(s.substr(i, s.size() - i));
					strVec.pop_back();
				}
			}
		}
	}
	vector<vector<string> > partition(string s) 
	{
		dfs(s);
		return result;
	}
};