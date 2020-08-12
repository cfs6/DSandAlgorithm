/*给定一棵二叉树，判断琪是否是自身的镜像（即：是否对称）*/
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
	bool isSym(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if ((root1 == nullptr&&root2 != nullptr) || (root1 != nullptr && root2 == nullptr))
			return false;
		return root1->val == root2->val && isSym(root1->left, root2->right)
			&& isSym(root1->right, root2->left);
	}

	bool isSymmetric(TreeNode* root) {
		return isSym(root, root);
	}
};