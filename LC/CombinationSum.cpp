/*
����һ���ѡ����һ��Ŀ�������ҳ���ѡ���������͵���target��������ϡ�
ÿ�����ֿ��Ա�ʹ��������
����е�����Ҫ����������
����в��ܰ����ظ������
���֮���������������С�������αȽϣ�С������ǰ�棬���������ͬ���������ֵ��ͬ����Ƚ���һ������
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


