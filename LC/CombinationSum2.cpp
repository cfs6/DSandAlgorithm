/*
����һ���ѡ����һ��Ŀ�������ҳ���ѡ���������͵���target��������ϡ�
ÿ��������һ�������ֻ��ʹ��һ�Ρ�
����е�����Ҫ����������
����в��ܰ����ظ������
���֮���������������С�������αȽϣ�С������ǰ�棬���������ͬ���������ֵ��ͬ����Ƚ���һ������
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
	//������Ȼ��dfs
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

