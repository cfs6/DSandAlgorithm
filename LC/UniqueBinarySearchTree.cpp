//给定一个值n，能构建出多少不同的值包含1...n的二叉搜索树（BST）？
class Solution {
public:
	/**
	*
	* @param n int整型
	* @return int整型
	*/
	/*考虑根节点，设对于任意根节点k，有f(k)种树的可能。
    比k小的k-1个元素构成k的左子树。则左子树有f(k-1)种情况。
    比k大的n-k个元素构成k的右子树。则右子树有f(n-k)种情况。
    易知，左右子树相互独立，所以f(k)=f(k-1)*f(n-k)。*/
	//采用dp方法由小到大更新res[]
	int numTrees(int n) {
		if (n == 0)
			return 1;
		int* res = new int[n + 1];
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			res[i] = 0;
			for (int j = 1; j <= i; ++j)
			{
				res[i] += res[j - 1] * res[i - j];
			}
		}
		return res[n];
	}
};