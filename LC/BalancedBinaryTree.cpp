/*判断给定的二叉树是否是平衡的 
在这个问题中，定义平衡二叉树为每个节点的左右两个子树高度差的绝对值不超过1的二叉树*/
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
	* @return bool布尔型
	*/
	bool helper(TreeNode* root, int& depth)
	{
		if (root == nullptr)
		{
			depth = 0;
			return true;
		}
		int left, right;
		if (helper(root->left, left) && helper(root->right, right))
		{
			if (abs(left - right) <= 1)
			{
				depth = 1 + max(left,right);
				return true;
			}
		}
		return false;
	}

	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return helper(root, depth);
	}





	//直接递归方法
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
			return true;
		if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1))
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};