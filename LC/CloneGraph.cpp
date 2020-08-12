/*��Ŀ����
����Ҫ����һ������ͼ��ͼ��ÿ���ڵ㶼����һ����ǩ�������ھ��б� 
��������ͼ�����µķ������л��� 
�ڵ�ı�ǩ�ǻ�����ͬ�ģ� 
����ʹ�á�#����Ϊ�ڵ�֮��ķָ�����ʹ�á�,����Ϊ�ڵ��ǩ�ͽڵ�Ľڵ��ھӵķָ����� */
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
	//����unorder_map����ɽڵ���½ڵ�֮��Ķ�Ӧ��Ӧ��ϵ����dfs������ͼ�������½ڵ�
	//������֮����ݾɽڵ��neighbors���齫�½ڵ��neighbors���鲹������

	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nmap;
	void dfs(UndirectedGraphNode* node)
	{
		if (node == nullptr)
			return;
		if (nmap.count(node))           //��ĳ�ڵ�ָ���Լ����Ի�����ֱ�ӷ���
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
			}                                  //nmap[nmfirst] ���½ڵ����neighbors����
		}

		return nmap[oldNode];
	}
};