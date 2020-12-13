/*
给出一组候选数和一个目标数，找出候选数中起来和等于target的所有组合。
每个数字在一个组合中只能使用一次。
组合中的数字要按递增排序
结果中不能包含重复的组合
组合之间的排序按照索引从小到大依次比较，小的排在前面，如果索引相同的情况下数值相同，则比较下一个索引
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
	//先排序然后dfs
	vector<vector<int>> result;
	vector<int> res;

	void dfs(vector<int> num, int start, int& sum, int target)
	{
		if (sum == target)
		{
			result.push_back(res);
			return;
		}
		else if (sum > target)
		{
			return;
		}
		for (int i = start; i < num.size(); ++i)
		{
			res.push_back(num[i]);
			int temp = num[i];
			sum += num[i];
			dfs(num, i + 1, sum, target);
			sum -= temp;
			res.pop_back();
		}

	}

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		if (num.size() == 0)
			return result;
		sort(num.begin(), num.end());
		int sum = 0;
		dfs(num, 0, sum, target);

		set<vector<int>> resSet;
		for (auto r : result)
		{
			resSet.insert(r);
		}
		result.clear();
		for (auto rSet : resSet)
		{
			result.push_back(rSet);
		}
		return result;
	}
};

