/*给出一个可能包含重复元素的整数集合S，返回该整数集合的所有子集。 
注意：
你给出的子集中的元素要按非递减的顺序排列 
给出的解集中不能包含重复的子集 */
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