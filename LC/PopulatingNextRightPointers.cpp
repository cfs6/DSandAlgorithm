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
	//�ݹ�
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

	//�ǵݹ� �������
	//���������ڵ㣬����next��ͬʱ������α�����ֱ��nullΪֹ��
	//Ȼ�󽫱���������һ���ײ������ڵ㣬�ڱ߽����߲��
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