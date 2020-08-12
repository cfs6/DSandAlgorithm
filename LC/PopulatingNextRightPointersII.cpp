#include<vector>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		while (root)
		{
			TreeLinkNode dummy(-1);
			TreeLinkNode *prev;
			prev = &dummy;
			for (auto p = root; p; p = p->next)
			{
				if (p->left)
				{
					prev->next = p->left;
					prev = prev->next;
				}
				if (p->right)
				{
					prev->next = p->right;
					prev = prev->next;
				}
			}
			root = dummy.next;
		}
	}



	void Connect(TreeLinkNode* root)
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
				if (q->left && !q->right && q->next)
				{
					TreeLinkNode* q2 = q;
					while (q2->next && !q2->next->left && !q2->next->right)
					{
						q2 = q2->next;
					}
					if (q2->next && q2->next->left)
						q->left->next = q2->next->left;
					if (q2->next && q2->next->right)
						q->left->next = q2->next->right;
				}

				if (q->right && q->next)
				{
					TreeLinkNode *q3 = q;
					while (q3->next && !q3->next->left && !q3->next->right)
					{
						q3 = q3->next;
					}
					if (q3->next && q3->next->left)
						q->right->next = q3->next->left;
					if (q3->next && q3->next->right)
						q->right->next = q3->next->right;
				}
				q = q->next;
			}
			p = p->left;
		}
	}
};


