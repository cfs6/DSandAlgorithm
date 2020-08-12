/*����һ���ַ���s���ָ�sʹ��s��ÿһ���Ӵ����ǻ��Ĵ� 
�������еĻ��ķָ�������ע�⣺���ؽ����˳����Ҫ�������ַ����е���ĸ˳��һ�¡��� */
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param s string�ַ���
	* @return string�ַ���vector<vector<>>
	*/
	//dfs���������������Ҫ����ַ�������result
	vector<string> strVec;
	vector<vector<string>> result;
	bool isPalindrome(string s) {        //�Է���������ж��Ƿ�Ϊ���Ĵ�
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