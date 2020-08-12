//Linked list cycle
//����һ���������������ػ�����ڽڵ㣬���û�л�������null 
#define NULL nullptr
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr||head->next==nullptr)
			return;
//		bool hasCycle = false;
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pNode = head;
		//���ݿ졢������Ƿ�����ж��Ƿ���ڻ�
		do {
			if (fast!=nullptr && fast->next != nullptr && slow != nullptr)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			else
				break;
		} while (fast != slow);
		//���졢�����������һΪnullptr,��������в����ڻ�
		if (fast == nullptr || fast->next == nullptr || slow == nullptr)
			return nullptr;
		//
		while (slow != pNode)
		{
			slow = slow->next;
			pNode = pNode->next;
		}
		return pNode;
	}
};