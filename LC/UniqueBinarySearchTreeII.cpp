//给定一个值n,请生成所有的存储值1...n.的二叉搜索树（BST）的结构
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val_) : val(val_) {}
};


class Solution {
public:
	/**
	*
	* @param n int整型
	* @return TreeNode类vector
	*/


	vector<TreeNode*> bfs(int start, int end)
	{
		vector<TreeNode*> res;
		if (start > end)
		{
			res.push_back(nullptr);
			return res;
		}
		for (int k = start; k <= end; ++k)
		{
			vector<TreeNode*> leftVec = bfs(start, k - 1);
			vector<TreeNode*> rightVec = bfs(k + 1, end);
			for (int i = 0; i < leftVec.size(); ++i)
			{
				for (int j = 0; j < rightVec.size(); ++j)
				{
					TreeNode* root = new TreeNode(k);
					root->left = leftVec[i];
					root->right = rightVec[j];
					res.push_back(root);
				}
			}
		}
		return res;
	}

	vector<TreeNode*> generateTrees(int n) {
		return bfs(1, n);
	}
};