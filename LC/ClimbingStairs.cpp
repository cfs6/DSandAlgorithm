/*������¥�ݣ���Ҫn����������¥�ݶ��� 
ÿ����ֻ��������1������2�����ж����ַ�����������¥�ݶ����� */
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int����
	* @return int����
	*/
	int climbStairs(int n) {
		if (n == 0)
			return 0;
		vector<int> dp(n+1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 2] + dp[i-1];
		}
		return dp[n];
	}
	int climbStairs(int m) {
		if (m == 1)
			return 1;
		if (m == 2)
			return 2;
		return climbStairs(m - 2) + climbStairs(m-1);
	}
};