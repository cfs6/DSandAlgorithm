/*给出一个升序排序的数组，将其转化为平衡二叉搜索树（BST）*/
#include<vector>
using namespace std;
 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val_) : val(val_) {}
 };


class Solution {
public:
	/**
	*
	* @param num int整型vector
	* @return TreeNode类
	*/
	//注意边界
	TreeNode* toBST(vector<int>& num,int begin, int end)
	{
		if (begin > end)
			return nullptr;
		if (begin == end)
			return new TreeNode(num[begin]);
		int vSize = end - begin + 1;
		int mid = begin + vSize / 2;
		TreeNode* root = new TreeNode(num[mid]);
		root->left = toBST(num, begin, mid-1);
		root->right = toBST(num, mid + 1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& num) {
		if (num.size() == 0)
			return nullptr;
		return toBST(num, 0, num.size()-1);
	}
};