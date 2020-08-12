/*给定一个二叉树和一个值sum，
请找出所有的根节点到叶子节点的节点值之和等于sum的路径*/
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
	* @param sum int整型
	* @return int整型vector<vector<>>
	*/
	//引用及非引用形参的使用解决了递归中res的回退问题
	//res每次通过函数调用，会复制一个新的vector存放数据
	void dfs(TreeNode* root, int sum, vector<int> res, vector<vector<int>>& result)
	{
		if (root == nullptr)
			return;
		res.push_back(root->val);
		if (root->val == sum && root->left == nullptr && root->right == nullptr)
		{
			result.push_back(res);
		}
		dfs(root->left, sum - root->val, res, result);

		dfs(root->right, sum - root->val, res, result);
	}
	vector<vector<int> > pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> res;
		dfs(root, sum, res, result);
		return result;
	}
};