//Print the tree crosswise
#include<stack>
void PrintTreeCrosswise(BinaryTreeNode* pRoot){
	if(pRoot==nullptr)
		return;
	stack<BinaryTreeNode*> pStack0;
	stack<BinaryTreeNode*> pStack1;
	pStack1.push(pRoot);
	int levelCount = 1;
	int nextLevelCount = 1;
	int pLevel = 1;
	pStack0.push(pRoot);
	while(!pStack0.empty()||!pStack1.empty()){
		levelCount = nextLevelCount;
		nextLevelCount *= 2;
		while(levelCount != 0){
			if(pLevel == 1){
				BinaryTreeNode* pNode = pStack0.top();
				std::cout<<pNode->m_value<<" ";
				if(pNode->m_left!=nullptr)
					pStack1.push(pNode->m_left);
				else
					nextLevelCount--;
				if(pNode->m_right!=nullptr)
					pStack1.push(pNode->m_left);
				else
					nextLevelCount--;
				pStack0.pop();
			}
			else if(pLevel == -1){
				BinaryTreeNode* pNode = pStack1.top();
				std::cout<<pNode->m_value<<" ";
				if(pNode->m_right!=nullptr)
					pStack0.push(pNode->m_right);
				else
					nextLevelCount--;
				if(pNode->m_left!=nullptr)
					pStack0.push(pNode->m_left);
				else
					nextLevelCount--;
				pStack1.pop()
			}
		}
		std::cout<<std::endl;
		pLevel = -pLevel;
	}
}
//不需要保存每层节点数levelCount nextLevelCount 因为一个stack保存了一层节点，打印完一个stack即打印了一层节点

