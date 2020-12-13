/*合并 k 个已排序的链表并将其作为一个已排序的链表返回。*/
#include<vector>
#include<list>
#include<iostream>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct compare {
	bool operator()(ListNode* l1, ListNode* l2)
	{
		return l1->val < l2->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, compare> pq;
		for (auto l : lists)
		{
			if(l)
				pq.push(l);
		}
		if (pq.empty())
			return nullptr;

		ListNode pHead(0);
		ListNode* result = &pHead;

		while (!pq.empty())
		{
			result->next = pq.top();
			pq.pop();
			result = result->next;
			if (result->next)
				pq.push(result->next);
		}

		return pHead.next;
	}
};