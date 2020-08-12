//Single Number
/*现在有一个整数类型的数组，数组中素只有一个元素只出现一次，其余的元素都出现两次。 
注意： 
你需要给出一个线性时间复杂度的算法，你能在不使用额外内存空间的情况下解决这个问题么？ */

class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @return int整型
	*/
	//根据异或运算的特性，将数组中所有数异或运算，由于相同数异或结果为0,且0与任何数异或
	//不改变当前数值，最后剩下来的就是只出现一次的数
	int singleNumber(int* A, int n) {
		int res = A[0];
		for (int i = 1; i < n; ++i)
		{
			res = res^A[i];
		}
		return res;
	}
};