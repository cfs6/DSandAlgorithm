/*给出一个非负整数数组，你最初在数组第一个元素的位置
数组中的元素代表你在这个位置可以跳跃的最大长度
判断你是否能到达数组最后一个元素的位置
例如
A =[2,3,1,1,4], 返回 true.
A =[3,2,1,0,4], 返回 false. */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<memory>
using namespace std;

class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @return bool布尔型
	*/
	/*贪心算法。每次都以当前位置pos的元素数字A[pos]前进，若当前位置元素为0，
	记录下当前能达到的最远距离，逐次回退一位并判定每次（都按贪心方法前进）
	是否能越过之前的最远距离（位置元素为0的点），若位置回退至0或-1（开始
	第一位的元素即为0）则返回false
	*/
	bool canJump(int* A, int n) {
		int pos = 0;
		while (pos < (n - 1))
		{
			int step = A[pos];
			if (step == 0)
			{
				int farest = pos;
				while ((pos + A[pos]) <= farest)
				{
					--pos;
					if (pos <= 0)
						return false;
				}
				continue;
			}
			pos += step;
		}
		return true;
	}
};
