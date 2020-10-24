/*你在爬楼梯，需要n步才能爬到楼梯顶部 
每次你只能向上爬1步或者2步。有多少种方法可以爬到楼梯顶部？ */
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int整型
	* @return int整型
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