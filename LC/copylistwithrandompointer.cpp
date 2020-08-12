/*
现在有一个这样的链表：链表的每一个节点都附加了一个随机指针，
随机指针可能指向链表中的任意一个节点或者指向空。
请对这个链表进行深拷贝。
*/
//Definition for singly-linked list with a random pointer.
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	//采用申请节点并复制键值->插入节点->复制随机指针->拆分链表的方式
	//复制节点后插入可以方便复制随机指针：找到原链表节点的随机指针位置，下一位置即为
	//拷贝的随机指针位置。
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr)
			return nullptr;
		RandomListNode* pNode;
		RandomListNode* cur = head;
		//复制节点并插入链表中
		while (cur != nullptr)
		{
			pNode = new RandomListNode(cur->label);
			RandomListNode* nextNode = cur->next;
			pNode->next = cur->next;
			cur->next = pNode;
			cur = nextNode;
		}
		//找到随机节点位置并复制
		cur = head;
		while (cur != nullptr)
		{
			pNode = cur->next;
			if (cur->random)
			{
				pNode->random = cur->random->next;
			}
			else
			{
				pNode->random = nullptr;
			}
			cur = pNode->next;
		}
		//拆分链表
		cur = head;
		RandomListNode* newHead = cur->next;
		while(cur!=nullptr)
		{
			pNode = cur->next;
			cur = cur->next = pNode->next;
			
		}
		return newHead;
	}
};