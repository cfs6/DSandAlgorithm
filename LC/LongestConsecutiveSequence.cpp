/*给定一个无序的整数类型数组，求最长的连续元素序列的长度。 
例如： 
给出的数组为[100, 4, 200, 1, 3, 2], 
最长的连续元素序列为[1, 2, 3, 4]. 返回这个序列的长度：4
你需要给出时间复杂度在O（n）之内的算法*/
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	/**
	*
	* @param num int整型vector
	* @return int整型
	*/
	//空间换时间
	//unordered_set基于散列表的查找时间为o(1)
	//对于num中的值，同时向后向前查找连续点，找到即删除，连续数集中最后端与
	//最前端的差即为连续数量
	int longestConsecutive(vector<int>& num) {
		int res = 0;
		unordered_set<int> numset(num.begin(),num.end());
		for (auto pernum:num)
		{
			if (find(numset.begin(), numset.end(), pernum) == numset.end())
			{
				continue;
			}
			int low = pernum;
			int high = pernum;
			numset.erase(pernum);
			while (find(numset.begin(), numset.end(), high + 1) != numset.end())
			{
				numset.erase(++high);
			}
			while (find(numset.begin(), numset.end(), low - 1) != numset.end())
			{
				numset.erase(--low);
			}
			res = max(res, high - low + 1);
		}
		return res;
	}
};