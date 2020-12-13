//û���ظ������ֵ���������
/*
����һ�����֣����ظ������ֵ���������
���磺
[1,2,3]��������������
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], [3,2,1].
���������������е�λ�ÿ�ǰΪ���ȼ������ֵ��������������
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