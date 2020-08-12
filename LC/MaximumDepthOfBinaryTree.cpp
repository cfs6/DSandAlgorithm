/*求给定二叉树的最大深度， 
最大深度是指树的根结点到最远叶子结点的最长路径上结点的数量。*/
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
	* @return int整型
	*/
	
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr&&root->right == nullptr)
			return 1;
		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};