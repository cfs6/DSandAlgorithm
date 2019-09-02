//Delete the duplicated node
void deleteDuplicated(ListNode** pHead){
	if(*pHead == nullptr)
		return;
	if(*pHead->next == nullptr)
		return;
	ListNode* pNode = *pHead;
	while(pNode != nullptr){
		ListNode* postNode = nullptr;
		ListNode* post2Node = nullptr;
		ListNode* post3Node = nullptr;
		while(pNode->value != pNode->next->value){
			pNode = pNode->next;
		}
		postNode = pNode->next;
		post2Node = postNode->next;
		post3Node = post2Node->next;
		ListNode->value = post2Node->value;
		ListNode->next = post2Node->next;
		postNode->value = post3Node->value;
		postNode->value = post3Node->next;
		delete post2Node;
		post2Node == nullptr;
		delete post3Node;
		post3Node ==nullptr;
		pNode = pNode->next;
	}

}
