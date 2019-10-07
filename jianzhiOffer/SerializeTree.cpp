//Serialize a tree
#include<iostream>

//using namespace std;
struct BinaryTreeNode {
	int m_value;
	BinaryTreeNode* m_left;
	BinaryTreeNode* m_right;
};

void SerializeTree(BinaryTreeNode* pRoot, std::ostream& stream) {
	if (pRoot == nullptr) {
		stream << "$";
		return;
	}
	stream<<pRoot->m_value<<',';
	SerializeTree(pRoot->m_left, stream);
	SerializeTree(pRoot->m_right, stream);
}

void Deserialize(BinaryTreeNode** pRoot, std::istream& stream) {
	int number;
	stream >> number;
	*pRoot = new BinaryTreeNode;
	(*pRoot)->m_value = number;
	(*pRoot)->m_left = nullptr;
	(*pRoot)->m_right = nullptr;

	Deserialize(&((*pRoot)->m_left), stream);
	Deserialize(&((*pRoot)->m_right), stream);
}

