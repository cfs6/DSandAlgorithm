/*题目给出一个字符串s1，我们可以用递归的方法将字符串分成两个非空的子串来
将s1表示成一个二叉树
将字符串乱序的方法是：选择任意的非叶子节点，交换它的两个孩子节点。
例如：如果我们选择节点“gr”交换他的两个孩子节点，就会产生一个乱序字符串"rgeat".
给出两个长度相同的字符串s1 和 s2，请判断s2是否是s1的乱序字符串。
*/
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param s1 string字符串
	* @param s2 string字符串
	* @return bool布尔型
	*/
	

	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int allChar[26] = {0};
		for (int i = 0; i < s1.size(); ++i)
		{
			allChar[s1[i]-'a']++;
			allChar[s2[i]-'a']--;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (allChar[i] != 0)
				return false;
		}
		for (int i = 1; i < s1.size(); ++i)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
				isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
				isScramble(s1.substr(i), s2.substr(0, s2.size()-i)))
				return true;
		}
		return false;
	}
};