/*给定一个二叉树和一个值sum，
判断是否有从根节点到叶子节点的节点值之和等于sum的路径*/
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
	/**
	*
	* @param root TreeNode类
	* @param sum int整型
	* @return bool布尔型
	*/
	//递归
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		if (sum == root->val && root->left == nullptr && root->right == nullptr)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};