//跳跃游戏II
/*给出一个非负整数数组，你最初在数组第一个元素的位置
数组中的元素代表你在这个位置可以跳跃的最大长度
你的目标是用最少的跳跃次数来到达数组的最后一个元素的位置
例如
给出数组 A =[2,3,1,1,4]
最少需要两次才能跳跃到数组最后一个元素的位置。
（从数组下标为0的位置跳长度1到达下标1的位置，
然后跳长度3到数组最后一个元素的位置） */
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @return int整型
	*/


	int jump(int* A, int n) {
		int jumps = 0, curEnd = 0, curFurthest = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			curFurthest = max(curFurthest, i + A[i]);
			if (i == curEnd)
			{
				jumps++;
				curEnd = curFurthest;
			}
		}
		return jumps;
	}
};