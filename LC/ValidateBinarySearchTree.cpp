/*�жϸ����Ķ������Ƿ���һ��������������BST��*/
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
	* @return bool������
	*/
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;
		if (root->left && root->right)
		{
			if (root->left->val >= root->val || root->val >= root->right->val)
				return false;
			else
				return isValidBST(root->left) && isValidBST(root->right);
		}

		else if (root->left == nullptr && root->right)
		{
			if (root->right->val <= root->val)
				return false;
			else
			{
				return isValidBST(root->right);
			}
		}
		else if (root->right == nullptr && root->left)
		{
			if (root->left->val >= root->val)
			{
				return false;
			}
			else
			{
				return isValidBST(root->left);
			}
		}
		else
			return true;
	}
};