//print list reversingly recursively

void printListReversingly(ListNode* pHead){
	if(pHead == nullptr)
		return 0;
	ListNode* pNode = pHead;
	if(pNode->next!=nullptr)
		printListReversingly(pNode->next);
	cout<<pNode->value;
}


