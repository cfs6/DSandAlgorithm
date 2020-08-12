/*给出一个三角形，计算从三角形顶部到底部的最小路径和，
每一步都可以移动到下面一行相邻的数字， 
例如，给出的三角形如下： 
[↵     [2],↵    [3,4],↵   [6,5,7],↵  [4,1,8,3]↵]
最小的从顶部到底部的路径和是2 + 3 + 5 + 1 = 11。*/
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
	//dp 每个位置i（除去边界位置）的值为上一行i-1和i中较小者+当前值
	//边界位置  最左侧为i+当前值   最右侧为i-1+当前值
	vector<int> *dp;
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0)
			return 0;
		dp = new vector<int>[triangle.size()];
		dp[0].push_back(triangle[0][0]);

		for (int i = 1; i < triangle.size(); ++i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				dp[i].push_back(0);
			}
		}
		for (int i = 1; i < triangle.size(); ++i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				if (j >= 1 && j<triangle[i].size() - 1)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
				}
				else if (j == triangle[i].size() - 1)
				{
					dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
				}
			}
		}
		int minNum = dp[triangle.size() - 1][0];
		for (int i = 1; i < triangle[triangle.size() - 1].size(); ++i)
		{
			minNum = min(minNum, dp[triangle.size() - 1][i]);

		}
		return minNum;
	}
};

int main()
{
	Solution sol;
	int res;
	vector<vector<int> > triangle;
	vector<int> t;
	t.push_back(-1);
	triangle.push_back(t);
	t.clear();
	t.push_back(2);
	t.push_back(3);
	triangle.push_back(t);
	t.clear();
	t.push_back(1);
	t.push_back(-1);
	t.push_back(-3);
	triangle.push_back(t);

	res = sol.minimumTotal(triangle);

	cout << res << endl;
	system("pause");
	return 0;
}