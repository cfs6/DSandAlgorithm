//Print the tree from the top to bottom row by row
#include<queue>
void PrintRowbyRow(BinaryTreeNode* pRoot){
	if(pRoot==nullptr)
		return;
	Stack<BinaryTreeNode*> pStack;
	int levelCount = 1;
	int nextLevelCount = 1;
	pStack.push(pRoot);
	while(!pStack.empty()){
		levelCount = nextLevelCount;
		nextLevelCount *= 2;
		while(levelCount!=0){
			BinaryTreeNode* pNode = pStack.front();
			std::cout<<pNode->m_value<<" ";
			if(pNode->left!=nullptr){
				pStack.push(pNode->left);
			}
			else
				--nextLevelCount;
			if(pNode->right!=nullptr){
				pStack.push(pNoed->right);
			}
			else
				--nextLevelCount;
			levelCount--;
			pStack.pop();
		}
		std::cout<<std::endl;
	}
}
