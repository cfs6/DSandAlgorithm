/*����·����n������վ����i������վ����������gas[i]. 
����һ���������������������װ���͡��Ӽ���վi�ߵ���һ������վ��i+1��
���ѵ�������cost[i]�����һ������վ�������տ�ʼ��ʱ����������û�����͡� 
����ĸ�����վ���������ڻ���·����һȦ�����ؼ���վ���±꣬���û�д𰸵Ļ�����-1�� 
ע�⣺ 
�𰸱�֤Ψһ*/
#include<vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param gas int����vector
	* @param cost int����vector
	* @return int����
	*/
	//��0->n-1ÿ������վ��ʼ������+=gas[j]��-=cost[j]������ǰ������С��0��˴�ѭ��������Ҫ��
	//��count���������ļ���վ��Ŀ����ѭ������count==n������ĳ�ڵ�ʧ����϶��޷��ﵽ��������,
	//��˴�ѭ���ﵽҪ�� ����˴�ѭ����ʼ�ļ���վi
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int currentGas;
		int count;
		for (int i = 0; i < n; ++i)
		{
			currentGas = 0;
			count = 0;
			int j = i;
			while (j != n)
			{
				currentGas += gas[j];
				currentGas -= cost[j];
				if (currentGas < 0)
					break;
				count++;
				++j;
			}
			j = 0;
			while (j != i)
			{
				currentGas += gas[j];
				currentGas -= cost[j];
				if (currentGas < 0)
					break;
				count++;
				++j;
			}
			if (count == n)
			{
				return i;
			}
		}
		return -1;
	}
};


