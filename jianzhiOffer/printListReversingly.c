//print the list reversingly iteratively
#include<stack>
void printListReversingly(ListNode* pHead){
	if(pHead==nullptr)
		return 0;
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while(pNode->next!=nullptr){
		nodes.push(pNode);
		pNode = pNode->next;
	}
	while(!nodes.empty()){
		std::cout<<nodes.top()->value<<endl;
		nodes.pop();
	}
}


