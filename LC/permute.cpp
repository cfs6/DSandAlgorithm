//没有重复项数字的所有排列
/*
给出一组数字，返回该组数字的所有排列
例如：
[1,2,3]的所有排列如下
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], [3,2,1].
（以数字在数组中的位置靠前为优先级，按字典序排列输出。）
*/
#include<vector>
#include<set>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	vector<int> res;
	void dfs(vector<int>& num, deque<bool>& used)
	{
		if (res.size() == num.size())
		{
			result.push_back(res);
			return;
		}
		for (int i = 0; i < num.size(); ++i)
		{
			if (used[i])
				continue;
			res.push_back(num[i]);
			used[i] = true;
			dfs(num, used);
			res.pop_back();
			used[i] = false;
		}
	}

	vector<vector<int> > permute(vector<int> &num) {
		int nsize = num.size();
		deque<bool> used(nsize, false);
		dfs(num, used);
		sort(num.begin(), num.end());
		return result;
	}
};