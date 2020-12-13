/*假设你有一个数组，其中第i个元素是某只股票在第i天的价格。
如果你最多只能完成一笔交易(即买一股和卖一股股票)，设计一个算法来求最大利润。*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param prices int整型vector
	* @return int整型
	*/
	int maxProfit(vector<int>& prices) {
		if (prices.size()<2)
			return 0;
		int profit = 0;
		for (int i = 0; i<prices.size() - 1; ++i)
		{
			for (int j = i + 1; j<prices.size(); ++j)
			{
				profit = max(profit, prices[j] - prices[i]);
			}
		}
		return profit;
	}
};