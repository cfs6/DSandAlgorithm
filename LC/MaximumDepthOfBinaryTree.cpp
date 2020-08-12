/*������������������ȣ� 
��������ָ���ĸ���㵽��ԶҶ�ӽ����·���Ͻ���������*/
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
	* @return int����
	*/
	
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr&&root->right == nullptr)
			return 1;
		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};