#include<vector>
using namespace std;
//Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	//递归
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		if (root->left && root->right)
			root->left->next = root->right;
		if (root->next && root->right)
			root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
	}

	//非递归 层序遍历
	//保存最左侧节点，建立next的同时，做层次遍历，直到null为止，
	//然后将变量跳到下一个阶层的最左节点，在边建立边层次
	void Connect(TreeLinkNode *root)
	{
		if (!root)
			return;
		TreeLinkNode *p = root;
		TreeLinkNode *q;
		while (p->left)
		{
			q = p;
			while (q)
			{
				if (q->left && q->right)
				{
					q->left->next = q->right;
				}
				if (q->next)
				{
					q->right->next = q->next->left;
				}
				q = q->next;
			}
			p = p->left;
		}
	}
};