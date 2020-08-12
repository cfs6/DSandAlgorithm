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
	* @param root TreeNode��
	* @return int����vector
	*/
	/*
	���ҵ�������ӽڵ㣬��ջ����;�����ڵ㣬������˿�ʼ������ջ��Ԫ���Ƿ�����
	�ӽڵ㲢�����ӽڵ�δ���ʹ��������Ƿ�ֹ���ݵ��˽ڵ�ʱ�ֽ����ӽڵ���ջ���ʣ���
	�������ӽڵ��Ҹ����ӽڵ�δ�����ʹ�������ջ���������ҵ�����˵��ӽڵ�
	�������ջ���������ӽڵ㣬�����ӽڵ��Ա�Ǳ����ʹ�,ֱ�ӽ��ýڵ���ʡ�
	*/
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> resVector;
		if (root == nullptr)
			return resVector;
		stack<TreeNode*> traverseStack;
		TreeNode* pRoot = root;
		TreeNode* rightNode = nullptr; //rightNode��Ϊ�Ƿ���ʹ������ӽڵ�ı��
		while (pRoot)
		{
			traverseStack.push(pRoot);
			pRoot = pRoot->left;
		}
		while (!traverseStack.empty())
		{
			TreeNode* resNode = traverseStack.top();
			//�������ӽڵ㣬�����ӽڵ��Ա�Ǳ����ʹ���ֱ�ӽ��ýڵ���ʡ�
			//�����ñ�Ǹ���
			if (resNode->right == nullptr||rightNode==resNode->right)
			{
				resVector.push_back(resNode->val);
				traverseStack.pop();
				rightNode = resNode;         //Ӧ�ڷ���ʱ���±�Ƕ�������ջʱ
			}
			//�������ӽڵ��Ҹ����ӽڵ�δ�����ʹ�������ջ��
			//�������ҵ�����˵��ӽڵ㲢�����ջ��
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