/*由于二分查找法每次需要找到中点，而链表的查找中间点可以通过快慢指针来操作。
找到中点后，要以中点的值建立一个数的根节点，然后需要把原链表断开，
分为前后两个链表，都不能包含原中节点，然后再分别对这两个链表递归调用原函数，
分别连上左右子节点即可。*/

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
	* @param head ListNode类
	* @return TreeNode类
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