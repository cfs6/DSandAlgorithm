//SingleNumberII
/*现在有一个整数类型的数组，数组中只有一个元素只出现一次，其余元素都出现三次。你需要找出只出现一次的元素 
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
	//int类型共32位，将数组中n个数二进制各位1累加后%3,若为出现三次的数，该位为0，若为1则
	//说明是仅出现一次的数的二进制位。
	int singleNumber(int* A, int n) {
		int res = 0;
		for (int i = 0; i < 32; ++i)
		{
			int bit = 0; 
			for (int j = 0; j < n; ++j)
			{
				bit += (A[j] >> i) & 1;  //右移i位与0000001求余得到最后一位（循环中当前第i位）
			}                            //的数值
			res |= (bit % 3) << i;       //求余判断该为是否为重复数值，左移恢复原位置，
		}                                //或运算组合
		return res;
	}
};