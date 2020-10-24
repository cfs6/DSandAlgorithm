/*给出一个只包含大小写字母和空格的字符串s，请返回字符串中最后一个单词的长度
如果字符串中没有最后一个单词，则返回0
注意：单词的定义是仅由非空格字符组成的字符序列。
例如：
s ="Hello World",
返回5。 */
/*
注意各种用例，如" "、 " a"、 " a "等
*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (s == nullptr)
			return 0;
		int lastSpace = 0;
		string str = s;
		lastSpace = str.rfind(' ');
		while (lastSpace == (str.length() - 1))
		{
			str = str.substr(0, str.size() - 1);
			if (str.length() == 0)
				return 0;
			lastSpace = str.rfind(' ');
			if (lastSpace == 0)
				break;
		}
		if (str.length() == 1 && lastSpace == 0)
			return 0;
		else
			return str.length() - 1 - lastSpace;
	}
};