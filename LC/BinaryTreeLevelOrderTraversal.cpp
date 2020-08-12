/*����һ�������������ظö�������������Ľ�����������ң�һ��һ��ر����� */
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
	* @param root TreeNode��
	* @return int����vector<vector<>>
	*/
	//ע���п�
	vector<vector<int>> result;
	vector<int> res;
	vector<vector<int> > levelOrder(TreeNode* root) {
		if (root == nullptr)
		{
			return result;
		}
		int levelNum = 0;
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		while (!nodeQueue.empty())
		{
			levelNum = nodeQueue.size();
			res.clear();
			while (levelNum != 0)
			{
				TreeNode* node = nodeQueue.front();
				res.push_back(node->val);
				if(node->left)
					nodeQueue.push(node->left);
				if(node->right)
					nodeQueue.push(node->right);
				nodeQueue.pop();
				levelNum--;
			}
			result.push_back(res);
		}
		return result;
	}
};