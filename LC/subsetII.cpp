/*����һ�����ܰ����ظ�Ԫ�ص���������S�����ظ��������ϵ������Ӽ��� 
ע�⣺
��������Ӽ��е�Ԫ��Ҫ���ǵݼ���˳������ 
�����Ľ⼯�в��ܰ����ظ����Ӽ� */
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<int> temp;

	void dfs(vector<int> set, int start)
	{
		result.push_back(temp);
		for (int i = start; i < set.size(); ++i)
		{
			temp.push_back(set[i]);
			dfs(set, i + 1);
			while (i < set.size() && set[i + 1] == set[i])
				i++;
			temp.pop_back();
		}
	}

	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		dfs(S, 0);
		return result;
	}
};