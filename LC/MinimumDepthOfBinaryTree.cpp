//Minimum depth of binary tree
//���������������С��ȡ�
//��С�����ָ���ĸ���㵽���Ҷ�ӽ������·���Ͻ���������
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
	/**
	*
	* @param root TreeNode��
	* @return int����
	*/
	//����BFS��������Ҷ�ڵ����ڵĲ�����Ϊ��С���
	//numLevel����ֱ𱣴浱ǰ��level����ǰ�����һ��nextLevel�������Ľڵ���Ŀ
	//����ǰ������нڵ㱻������δ������Ҷ�ڵ�ʱ�������ݼ�
	int run(TreeNode* root) {
		if (root == nullptr)
			return 0;
//		int minLevel = 0;
//		int numLevel = 1;
		vector<int> numLevel(65535);                     //��Ÿ���ڵ���Ŀ����
		int level = 1;                                   //��ǰ��
		int nextLevel = level + 1;                       //��ǰ�����һ��
		queue<TreeNode*> nodeQueue;                      //�ڵ����
		nodeQueue.push(root);
		numLevel[level] = 1;
		while (!nodeQueue.empty())
		{
			if ((nodeQueue.front()->left == nullptr) &&
				(nodeQueue.front()->right == nullptr))
			{
//				return minLevel;                         //����minLevel������level
				return level;                            //��Ϊ��С���
			}		
			if (nodeQueue.front()->left != nullptr)
			{
				nodeQueue.push(nodeQueue.front()->left);
				numLevel[nextLevel]++;
			}
			if (nodeQueue.front()->right != nullptr)
			{
				nodeQueue.push(nodeQueue.front()->right);
				numLevel[nextLevel]++;
			}		
			nodeQueue.pop();
			numLevel[level]--;
			if (numLevel[level] == 0)
			{
				level++;
				nextLevel++;
//				minLevel++;
			}
		}
	}
};