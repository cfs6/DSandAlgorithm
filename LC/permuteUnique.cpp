//有重复项数字的所有排列
/*
给出一组可能包含重复项的数字，返回该组数字的所有排列
例如；
[1,1,2]的排列如下：
[1,1,2],[1,2,1], [2,1,1].
*/
#include<vector>
#include<set>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	/*
	1. 解决重复数字问题  先对容器num进行排序，保证重复数字相邻，
	这样在后续操作中，利用条件，若后一数与前一数相等，则不处理
	2、解决数字是否进入排列list容器问题  使用额外bool类型容器used，
	区分当前值是否已进入排列当中
	3、解决排列问题  （1）若list长度等于num，则压入容器res
	（2）对容器num进行for循环  边界条件：  若当前值已使用过，不处理；
	若当前值与前一值相等，且前一值未使用过，不处理
	（举例：112，循环第一个1作第一位时，第二位是第二个1，会被记录，
	但是循环第二个1做第一位时，第二位是第一个1，就不会被记录，避免重复）
	当前值压入并依次作为排列list的元素，将used容器对应位置true
	将当前list、num、used和res送入排列函数，进行递归
	将used中对应位置false，list弹出当前值，继续for循环 */
	vector<vector<int>> result;
	void dfs(vector<int>& num, vector<int>& res, deque<bool>& used)
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
			if (i > 0 && num[i] == num[i - 1] && !used[i - 1])
				continue;
			res.push_back(num[i]);
			used[i] = true;
			dfs(num, res, used);
			used[i] = false;
			res.pop_back();
		}
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		if (num.size() == 0)
			return result;
		sort(num.begin(), num.end());
		deque<bool> used;
		for (int i = 0; i < num.size(); ++i)
			used.push_back(false);
		vector<int> res;
		dfs(num, res, used);

		return result;
	}
};






// 采用取两个量swap最后去重的方法，会爆栈
class Solution {
public:
	vector<vector<int>> result;
//	vector<int> res;
	void dfs(vector<int>& num, int start)
	{
		if (start == num.size() - 1)
			return;
		for (int i = start; i < num.size()-1; ++i)
		{
			for (int j = i+1; j < num.size(); ++j)
			{
				result.push_back(num);
				swap(num[i], num[j]);
				dfs(num,start+1);
				swap(num[i], num[j]);
			}
		}


	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		
		if (num.size() == 0)
			return result;
		dfs(num, 0);
		return result;
	}
};