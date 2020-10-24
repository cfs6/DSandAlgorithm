/*给出两个整数n和k，返回从1到n中取k个数字的所有可能的组合 
例如： 
如果n=4，k=2，结果为 
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/
#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int整型
	* @param k int整型
	* @return int整型vector<vector<>>
	*/
//	vector<vector<int>> result;
//	vector<int> res;

	void getRes(int num, int k, int n, vector<vector<int>>& result, vector<int>& res)
	{
		if (k == 0)
		{
			result.push_back(res);
			return;
		}
		if (num > n)
			return;
		res.push_back(num);
		getRes(num + 1, k - 1, n, result, res);
		res.pop_back();
		getRes(num + 1, k, n, result, res);
		
	}
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> result;
		vector<int>res;
		getRes(1, k,n,result, res);
		return result;
	}
};

//another way
void DFS(vector<vector<int>> &ret, vector<int> &path, int n, int start, int rest) {
	if (!rest)
		ret.push_back(path);
	else {
		for (int i = start; i <= n - rest + 1; ++i) {
			path.push_back(i);
			DFS(ret, path, n, i + 1, rest - 1);
			path.pop_back();
		}
	}
}
vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> ret;
	vector<int> path;
	DFS(ret, path, n, 1, k);
	return ret;
}