#include<vector>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	/**
	*
	* @param s string�ַ���
	* @return string�ַ���vector
	*/
	//�����ַ����Ƿ�����������ж��������
	bool isValid(string& s)
	{
		stringstream ss(s);
		int num;
		ss >> num;
		if (s.size() > 1)
			return s[0] != '0' && num >= 0 && num <= 255;
		return num >= 0 && num <= 255;
	}

	//str ����ַ���
	//strFrag ʣ����ַ���
	void getStr(vector<string>& res, string str, string restStr, int count)
	{
		if (count == 3 && isValid(restStr))
		{
			res.push_back(str + restStr);
		}
		for (int i = 1; i < 4 && i<restStr.size(); ++i)
		{
			string sub = restStr.substr(0, i);
			if (isValid(sub))
			{
				getStr(res, str + sub + '.', restStr.substr(i), count + 1);
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		string str;
		vector<string> res;
		getStr(res, str, s, 0);
		return res;
	}
};