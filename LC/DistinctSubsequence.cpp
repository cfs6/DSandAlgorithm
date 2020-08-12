/*给定两个字符串S和T，返回S子序列等于T的不同子序列个数有多少个？ 
字符串的子序列是由原来的字符串删除一些字符（也可以不删除）在不改变相对位置的情况下的剩余字符（例如，"ACE"is a subsequence of"ABCDE"但是"AEC"不是）
例如： 
S ="rabbbit", T ="rabbit"
返回3 */
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	/**
	*
	* @param S string字符串
	* @param T string字符串
	* @return int整型
	*/
	//递归 可能超时
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

	
	//dp dp[i][j] 子串i 母串j
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
