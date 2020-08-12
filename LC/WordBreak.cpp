//word break
/*
����һ���ַ���s��һ�鵥��dict��
�ж�s�Ƿ�����ÿո�ָ��һ���������У�
ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ���
*/
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
	//dp���� ��־s[0-i]�Ƿ�ɻ���Ϊdict�е��Ӵ�
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