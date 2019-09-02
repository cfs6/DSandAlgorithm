#include<stdlib.h>
#include<string>

struct listNode{
	char c;
	list* next;
}

bool isPalindrome(const listNode* head){
	if((!head)||(head->next==NULL))
		return false;
	ListNode *a = head;
	ListNode *b = head;
	while(b->next->next != NULL){
		a = a->next;
		b = b->next->next;
	}
	reverseList(const ListNode* head, const ListNode* a);
	while(a!=NULL){
		if(a.c != b.c)
			return false;
		a = a->next;
		b = b->next;
	}
	return true;
}


ListNode* reverseList(const ListNode* _head, const ListNode* _tail){
	ListNode* temp1 = NULL;
	ListNode* temp2 = NULL;
	if(_head != _tail){
		temp1 = _head;
		_head = _head->next;
		temp1->next = temp2;
		temp2 = temp1;
	}
	_head->next = temp2;
	
	return _head; 
}
