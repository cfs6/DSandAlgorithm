/*题目描述
本题要求复制一个无向图，图中每个节点都包含一个标签和它的邻居列表 
我们无向图用以下的方法序列化： 
节点的标签是互不相同的， 
我们使用“#”作为节点之间的分隔符，使用“,”作为节点标签和节点的节点邻居的分隔符。 */
#include<vector>
#include<unordered_map>
using namespace std;
/**
* Definition for undirected graph.*/
struct UndirectedGraphNode {
	int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	//采用unorder_map保存旧节点和新节点之间的对应对应关系，以dfs遍历旧图并创建新节点
	//遍历完之后根据旧节点的neighbors数组将新节点的neighbors数组补充完整

	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nmap;
	void dfs(UndirectedGraphNode* node)
	{
		if (node == nullptr)
			return;
		if (nmap.count(node))           //若某节点指向自己（自环），直接返回
			return;
		UndirectedGraphNode* pNode = new UndirectedGraphNode(node->label);
		nmap[node] = pNode;
		for (auto p:node->neighbors)
		{
			dfs(p);
		}
	}

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		UndirectedGraphNode* oldNode = node;
		dfs(node);
		
		for (auto nm : nmap)
		{
			for (auto nmfirst : nm.first->neighbors)
			{
				nm.second->neighbors.push_back(nmap[nmfirst]);
			}                                  //nmap[nmfirst] 将新节点加入neighbors数组
		}

		return nmap[oldNode];
	}
};