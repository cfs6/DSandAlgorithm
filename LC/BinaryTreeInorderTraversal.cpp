//给出一棵二叉树，返回这棵树的中序遍历 
#include<vector>
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
	* @return int整型vector
	*/
	vector<int> res;
	void inorder(TreeNode* root)
	{
		if (root->left)
		{
			inorder(root->left);
		}
		res.push_back(root->val);

		if (root->right)
		{
			inorder(root->right);
		}
	}


	vector<int> inorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return res;
		inorder(root);
		return res;
	}
};