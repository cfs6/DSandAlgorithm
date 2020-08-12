/*���ڶ��ֲ��ҷ�ÿ����Ҫ�ҵ��е㣬������Ĳ����м�����ͨ������ָ����������
�ҵ��е��Ҫ���е��ֵ����һ�����ĸ��ڵ㣬Ȼ����Ҫ��ԭ����Ͽ���
��Ϊǰ���������������ܰ���ԭ�нڵ㣬Ȼ���ٷֱ������������ݹ����ԭ������
�ֱ����������ӽڵ㼴�ɡ�*/

#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val_) :val(val_) {}
};


struct ListNode {
	int val;
	struct ListNode *next;
 };


class Solution {
public:
	/**
	*
	* @param head ListNode��
	* @return TreeNode��
	*/
	TreeNode* sortedListToBST(ListNode* head) {
		return toBST(head, nullptr);
	}

	TreeNode* toBST(ListNode* head, ListNode* tail)
	{
		if (head == tail)
			return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast != tail && fast->next != tail)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		root->left = toBST(head, slow);
		root->right = toBST(slow->next, tail);

		return root;
	}
};