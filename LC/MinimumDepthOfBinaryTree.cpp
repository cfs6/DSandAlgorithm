//Minimum depth of binary tree
//求给定二叉树的最小深度。
//最小深度是指树的根结点到最近叶子结点的最短路径上结点的数量。
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
	* @param root TreeNode类
	* @return int整型
	*/
	//基于BFS，搜索至叶节点所在的层数即为最小深度
	//numLevel数组分别保存当前层level、当前层的下一层nextLevel所包含的节点数目
	//当当前层的所有节点被遍历且未搜索到叶节点时，层数递加
	int run(TreeNode* root) {
		if (root == nullptr)
			return 0;
//		int minLevel = 0;
//		int numLevel = 1;
		vector<int> numLevel(65535);                     //存放各层节点数目数组
		int level = 1;                                   //当前层
		int nextLevel = level + 1;                       //当前层的下一层
		queue<TreeNode*> nodeQueue;                      //节点队列
		nodeQueue.push(root);
		numLevel[level] = 1;
		while (!nodeQueue.empty())
		{
			if ((nodeQueue.front()->left == nullptr) &&
				(nodeQueue.front()->right == nullptr))
			{
//				return minLevel;                         //不需minLevel，层数level
				return level;                            //即为最小深度
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