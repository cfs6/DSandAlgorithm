/*���������ַ���S��T������S�����е���T�Ĳ�ͬ�����и����ж��ٸ��� 
�ַ���������������ԭ�����ַ���ɾ��һЩ�ַ���Ҳ���Բ�ɾ�����ڲ��ı����λ�õ�����µ�ʣ���ַ������磬"ACE"is a subsequence of"ABCDE"����"AEC"���ǣ�
���磺 
S ="rabbbit", T ="rabbit"
����3 */
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	/**
	*
	* @param S string�ַ���
	* @param T string�ַ���
	* @return int����
	*/
	//�ݹ� ���ܳ�ʱ
	int result = 0;
	void makeTree(string S, int n, string T, int m)
	{
		if (n < S.size() && m < S.size())
		{
			for (int i = n; i < S.size(); ++i)
			{
				if (S[i] == T[m])
				{
					if (m == T.size() - 1)
					{
						result++;
					}
					else
					{
						makeTree(S, i + 1, T, m + 1);
					}
				}
			}
		}
	}

	int numDistinct(string S, string T) {
		makeTree(S, 0, T, 0);
		return result;
	}

	
	//dp dp[i][j] �Ӵ�i ĸ��j
	int numDistinct(string S, string T)
	{
		int n = S.length();
		int m = T.length();
		int ** dp = new int*[m + 1];
		for (int i = 0; i < m+1; ++i)
		{
			dp[i] = new int[n + 1];
		}

		for (int j = 0; j < n; ++j)
		{
			dp[0][j] = 1;
		}

		for (int i = 1; i < m + 1; ++i)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				if (S[j-1] == T[i-1])
				{
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};
