//����һ�ö������������������������� 
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
	* @param root TreeNode��
	* @return int����vector
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