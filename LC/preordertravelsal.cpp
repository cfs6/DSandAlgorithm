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
	* @param root TreeNode类
	* @return int整型vector
	*/
	/*
	从根节点开始，对当前节点及左子节点访问，对右子节点入栈
	对于从栈中取出的右节点，也要按照对当前节点及左子节点访问，对右子节点入栈的方式
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