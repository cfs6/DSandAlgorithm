/*��������һ�����飬���е�i��Ԫ����ĳֻ��Ʊ�ڵ�i��ļ۸�
��������ֻ�����һ�ʽ���(����һ�ɺ���һ�ɹ�Ʊ)�����һ���㷨�����������*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param prices int����vector
	* @return int����
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