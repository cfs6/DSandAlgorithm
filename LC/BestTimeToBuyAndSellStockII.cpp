/*假设你有一个数组，其中第i个元素表示某只股票在第i天的价格。
设计一个算法来寻找最大的利润。你可以完成任意数量的交易(例如，多次购买和出售股票的一股)。但是，你不能同时进行多个交易(即，你必须在再次购买之前卖出之前买的股票)。*/
//找到连续递增数间的差值求和即为最大利润
//若prices[i+1]比prices[i]小，则最大利润为从i+1处开始购买，若prices[i+1]比prices[i]大，//则将连续递增数之间的差值求和。
#include<vector>
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
		int res = 0;
		for (int i = 0; i<prices.size() - 1; i++)
		{
			if (prices[i + 1]>prices[i])
				res += prices[i + 1] - prices[i];
		}
		return res;
	}
};