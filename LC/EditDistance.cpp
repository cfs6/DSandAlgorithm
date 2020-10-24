/*������������word1��word2������㽫word1ת��Ϊword2������Ҫ���ٲ�������
����Զ�һ������ִ������3�ֲ�����
a���ڵ����в���һ���ַ�
b��ɾ�������е�һ���ַ�
c���滻�����е�һ���ַ�
*/
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param word1 string�ַ���
	* @param word2 string�ַ���
	* @return int����
	*/
	// dp[i][j]������word1��ǰi���Ӵ���Ϊword2��ǰj���Ӵ��Ļ���
	// ����i��j����Ϊ0������մ�:""
	// ����������ַ���ȣ���ô������һ���������,��abc��dfc                
	// ���������ab��df������һ����                
	// ��Ȼ��Ҫ��ɾ�������룬�޸���ȡ������С���Ǹ�
	int minDistance(string word1, string word2) {
		int strLength1 = word1.size();
		int strLength2 = word2.size();

		vector<vector<int> > res(strLength1 + 1, vector<int>(strLength2 + 1));
		for (int i = 0; i <= strLength1; ++i)
		{
			for (int j = 0; j <= strLength2; ++j)
			{
				if (i == 0)
				{
					res[i][j] = j;
				}
				else if (j == 0)
				{
					res[i][j] = i;
				}
				else
				{    //min()ֻ������������
					res[i][j] = min(res[i - 1][j] + 1, min(res[i][j - 1] + 1,
						res[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1)));
				}
			}
		}
		return res[strLength1][strLength2];
	}
};