/*�жϸ����Ķ������Ƿ���ƽ��� 
����������У�����ƽ�������Ϊÿ���ڵ���������������߶Ȳ�ľ���ֵ������1�Ķ�����*/
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
	* @param root TreeNode��
	* @return bool������
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





	//ֱ�ӵݹ鷽��
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