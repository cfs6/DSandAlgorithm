/*����һ�ö��������ж����Ƿ�������ľ��񣨼����Ƿ�Գƣ�*/
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