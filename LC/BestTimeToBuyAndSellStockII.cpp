/*��������һ�����飬���е�i��Ԫ�ر�ʾĳֻ��Ʊ�ڵ�i��ļ۸�
���һ���㷨��Ѱ���������������������������Ľ���(���磬��ι���ͳ��۹�Ʊ��һ��)�����ǣ��㲻��ͬʱ���ж������(������������ٴι���֮ǰ����֮ǰ��Ĺ�Ʊ)��*/
//�ҵ�������������Ĳ�ֵ��ͼ�Ϊ�������
//��prices[i+1]��prices[i]С�����������Ϊ��i+1����ʼ������prices[i+1]��prices[i]��//������������֮��Ĳ�ֵ��͡�
#include<vector>
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
		int res = 0;
		for (int i = 0; i<prices.size() - 1; i++)
		{
			if (prices[i + 1]>prices[i])
				res += prices[i + 1] - prices[i];
		}
		return res;
	}
};