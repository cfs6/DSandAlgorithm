/*实现函数next permutation（下一个排列）：将排列中的数字重新排列成字典序中的下一个更大的排列。
将排列中的数字重新排列成字典序中的下一个更大的排列。
如果不存在这样的排列，则将其排列为字典序最小的排列（升序排列）
需要使用原地算法来解决这个问题，不能申请额外的内存空间
下面有机组样例，左边是输入的数据，右边是输出的答案
1,2,3→1,3,2
3,2,1→1,2,3
1,1,5→1,5,1*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
	/*
	* 1.从后往前找到不满足递增排序的点
	* 2.如果不存在这样的点证明数组是非递增的，直接reverse，然后返回即可
	* 3.如果找到，例如上例中的7，则重新从后往前寻找大于3的第一个数，即5
	* 4.交换3和5的位置，然后将后面的数组升序排列，即可得到结果
	*/
public:
	void nextPermutation(vector<int> &num) {
		if (num.size() <= 1)
			return;
		int t = num.size() - 1;
		bool isMaxSorted = true;
		for (; t > 0; --t)
		{
			if (num[t] > num[t - 1])
			{
				isMaxSorted = false;
				break;
			}
		}
		if (isMaxSorted)
		{
			reverse(num.begin(), num.end());
			return;
		}
		int i = num.size() - 1;
		for (; i >= t; --i)
		{
			if (num[i] > num[t - 1])
			{
				swap(num[i], num[t - 1]);
				sort(num.begin() + t, num.end());
				return;
			}
		}
	}
};