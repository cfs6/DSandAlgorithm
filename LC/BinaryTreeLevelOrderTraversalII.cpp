/*����һ�������������ظö������ɵײ㵽����Ĳ��������
���������ң���Ҷ�ӽڵ㵽���ڵ㣬һ��һ��ı�����*/
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