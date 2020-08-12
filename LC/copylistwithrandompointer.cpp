/*
������һ�����������������ÿһ���ڵ㶼������һ�����ָ�룬
���ָ�����ָ�������е�����һ���ڵ����ָ��ա�
������������������
*/
//Definition for singly-linked list with a random pointer.
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	//��������ڵ㲢���Ƽ�ֵ->����ڵ�->�������ָ��->�������ķ�ʽ
	//���ƽڵ�������Է��㸴�����ָ�룺�ҵ�ԭ����ڵ�����ָ��λ�ã���һλ�ü�Ϊ
	//���������ָ��λ�á�
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr)
			return nullptr;
		RandomListNode* pNode;
		RandomListNode* cur = head;
		//���ƽڵ㲢����������
		while (cur != nullptr)
		{
			pNode = new RandomListNode(cur->label);
			RandomListNode* nextNode = cur->next;
			pNode->next = cur->next;
			cur->next = pNode;
			cur = nextNode;
		}
		//�ҵ�����ڵ�λ�ò�����
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
		//�������
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