//binary tree preorder traversal
#include<vector>
#include<stack>
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
	/*
	�Ӹ��ڵ㿪ʼ���Ե�ǰ�ڵ㼰���ӽڵ���ʣ������ӽڵ���ջ
	���ڴ�ջ��ȡ�����ҽڵ㣬ҲҪ���նԵ�ǰ�ڵ㼰���ӽڵ���ʣ������ӽڵ���ջ�ķ�ʽ
	*/
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> resVector;
		if (root == nullptr)
			return resVector;
		TreeNode* pRoot = root;
		stack<TreeNode*> rightStack;

		while (pRoot)
		{
			resVector.push_back(pRoot->val);
			if (pRoot->right)
			{
				rightStack.push(pRoot->right);
			}
			pRoot = pRoot->left;
		}
		while (!rightStack.empty())
		{
			TreeNode* pNode = rightStack.top();
			rightStack.pop();
			while (pNode)
			{
				resVector.push_back(pNode->val);
				
				if (pNode->right)
				{
					rightStack.push(pNode->right);
				}
				pNode = pNode->left;
			}

		}
		return resVector;
	}
};