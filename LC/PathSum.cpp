/*����һ����������һ��ֵsum��
�ж��Ƿ��дӸ��ڵ㵽Ҷ�ӽڵ�Ľڵ�ֵ֮�͵���sum��·��*/
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
	* @param sum int����
	* @return bool������
	*/
	//�ݹ�
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		if (sum == root->val && root->left == nullptr && root->right == nullptr)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};