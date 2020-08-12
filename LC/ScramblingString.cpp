/*��Ŀ����һ���ַ���s1�����ǿ����õݹ�ķ������ַ����ֳ������ǿյ��Ӵ���
��s1��ʾ��һ��������
���ַ�������ķ����ǣ�ѡ������ķ�Ҷ�ӽڵ㣬���������������ӽڵ㡣
���磺�������ѡ��ڵ㡰gr�����������������ӽڵ㣬�ͻ����һ�������ַ���"rgeat".
��������������ͬ���ַ���s1 �� s2�����ж�s2�Ƿ���s1�������ַ�����
*/
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param s1 string�ַ���
	* @param s2 string�ַ���
	* @return bool������
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