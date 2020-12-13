/*
给出一组候选数和一个目标数，找出候选数中起来和等于target的所有组合。
每个数字可以被使用无数次
组合中的数字要按递增排序
结果中不能包含重复的组合
组合之间的排序按照索引从小到大依次比较，小的排在前面，如果索引相同的情况下数值相同，则比较下一个索引
*/
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<int> res;
	void dfs(vector<int>& candidates, int start, int& sum, int target)
	{
		if (sum == target)
		{
			result.push_back(res);
			return;
		}
		if (sum > target)
		{
			return;
		}
		for (int i = start; i < candidates.size(); ++i)
		{
			int temp = candidates[i];
			sum += temp;
			res.push_back(candidates[i]);
			dfs(candidates, i, sum, target);
			sum -= temp;
			res.pop_back();
		}
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		if (candidates.size() == 0)
			return result;
		int sum = 0;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, sum, target);
		set<vector<int>> resSet;
		for (auto res : result)
		{
			resSet.insert(res);
		}
		result.clear();
		for (auto rSet : resSet)
		{
			result.push_back(rSet);
		}
		return result;
	}
};


