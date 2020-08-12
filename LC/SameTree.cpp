/*������������������д��һ���ж������������Ƿ���ȵĺ����� 
�ж�������������ȵ������ǣ������������Ľṹ��ͬ��������ͬ�Ľڵ��Ͼ�����ͬ��ֵ��*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
	/**
	*
	* @param p TreeNode��
	* @param q TreeNode��
	* @return bool������
	*/
	//ע�����ֵ����͵ݹ�
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		if (p != nullptr && q != nullptr && p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else if (p == nullptr && q == nullptr)
			return true;
		else 
			return false;
	}
};