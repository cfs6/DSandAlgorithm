//binary tree postorder traversal
//Non recursive
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
	先找到最左端子节点，以栈保存途径各节点，从最左端开始，根据栈顶元素是否有右
	子节点并且右子节点未访问过（加入标记防止回溯到此节点时又将右子节点入栈访问），
	若有右子节点且该右子节点未被访问过则将其入栈，并对其找到最左端的子节点
	并逐个入栈。若无右子节点，或右子节点以标记被访问过,直接将该节点访问。
	*/
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> resVector;
		if (root == nullptr)
			return resVector;
		stack<TreeNode*> traverseStack;
		TreeNode* pRoot = root;
		TreeNode* rightNode = nullptr; //rightNode作为是否访问过该右子节点的标记
		while (pRoot)
		{
			traverseStack.push(pRoot);
			pRoot = pRoot->left;
		}
		while (!traverseStack.empty())
		{
			TreeNode* resNode = traverseStack.top();
			//若无右子节点，或右子节点以标记被访问过，直接将该节点访问。
			//并将该标记更新
			if (resNode->right == nullptr||rightNode==resNode->right)
			{
				resVector.push_back(resNode->val);
				traverseStack.pop();
				rightNode = resNode;         //应在访问时更新标记而不是入栈时
			}
			//若有右子节点且该右子节点未被访问过则将其入栈，
			//并对其找到最左端的子节点并逐个入栈。
			else if(resNode->right!=nullptr && rightNode!=resNode->right)
			{
				TreeNode* rNode = resNode->right;
				while (rNode)
				{
					traverseStack.push(rNode);
					rNode = rNode->left;
				}
				rightNode = nullptr;
			}
		}
		return resVector;
	}
};