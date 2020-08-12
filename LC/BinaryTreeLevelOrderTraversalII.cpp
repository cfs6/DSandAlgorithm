/*给定一个二叉树，返回该二叉树由底层到顶层的层序遍历，
（从左向右，从叶子节点到根节点，一层一层的遍历）*/
#include<vector>
#include<queue>
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
	* @return int整型vector<vector<>>
	*/
	vector<int> res;
	vector<vector<int>> result;
	vector<vector<int> > levelOrderBottom(TreeNode* root) {
		if (root == nullptr)
			return result;
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		while (!nodeQueue.empty())
		{
			int queueSize = nodeQueue.size();
			int n = queueSize;
			res.clear();
			while (n != 0)
			{
				TreeNode* node = nodeQueue.front();
				if (node->left)
				{
					nodeQueue.push(node->left);
				}
				if (node->right)
				{
					nodeQueue.push(node->right);
				}
				res.push_back(node->val);
				n--;
				nodeQueue.pop();
			}
			result.push_back(res);
			
		}
		reverse(result.begin(), result.end());
		return result;
	}
};