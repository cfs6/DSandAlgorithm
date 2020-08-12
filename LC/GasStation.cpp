/*环形路上有n个加油站，第i个加油站的汽油量是gas[i]. 
你有一辆车，车的油箱可以无限装汽油。从加油站i走到下一个加油站（i+1）
花费的油量是cost[i]，你从一个加油站出发，刚开始的时候油箱里面没有汽油。 
求从哪个加油站出发可以在环形路上走一圈。返回加油站的下标，如果没有答案的话返回-1。 
注意： 
答案保证唯一*/
#include<vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param gas int整型vector
	* @param cost int整型vector
	* @return int整型
	*/
	//从0->n-1每个加油站开始遍历，+=gas[j]并-=cost[j]，若当前汽油量小于0则此次循环不满足要求
	//以count计量经过的加油站数目，若循环结束count==n（若有某节点失败则肯定无法达到此条件）,
	//则此次循环达到要求， 输出此次循环开始的加油站i
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


