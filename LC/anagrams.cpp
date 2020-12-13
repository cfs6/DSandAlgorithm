/*
换位词
题目描述
给出一个字符串数组，返回所有互为“换位词（anagrams）”的字符串的组合。（换位词就是包含相同字母，但字母顺序可能不同的字符串）
备注：所有的输入都是小写字母
例如：
输入 ["ape","pea","tax"]
返回 ["ape","pea"]
*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	//题目未说清输出结果中的string顺序，过不了牛客
	bool isAnagram(string str1, string str2)
	{
		if (str1.length() != str2.length())
			return false;
		vector<int> cha(26, 0);
		for (int i = 0; i < str1.length(); ++i)
		{
			cha[str1[i] - 'a']++;
			cha[str2[i] - 'a']--;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (cha[i] != 0)
				return false;
		}
		return true;
	}

	vector<string> anagrams(vector<string> &strs) {
		vector<string> res;
		if (strs.size() <= 0)
			return res;
		if (strs.size() == 1)
			return strs;
		//		bool isFinish = false;
		for (int i = 0; i < strs.size(); ++i)
		{

			for (int j = i + 1; j < strs.size(); ++j)
			{
				string str1 = strs[i];
				string str2 = strs[j];
				if (isAnagram(str1, str2))
				{
					//					if (!isFinish)
					//					{
					res.push_back(str1);
					res.push_back(str2);
					//						isFinish = true;
					//					}
					//					else
					//					{
					//						res.push_back(str2);
					//					}
				}
			}
		}
		set<string> strSet;
		for (auto r : res)
			strSet.insert(r);
		res.clear();
		for (auto sSet : strSet)
			res.push_back(sSet);
		return res;
	}
};

