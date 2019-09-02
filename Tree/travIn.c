// Inorder traverse iteratively
#include"Tree.h"

template<typename T>
void goLeftBranch(BinNodePosition<T> x, Stack<BinNodePosition<T>> &S){
	while(x){
		S.push(x);
		x = x->lChild;
	}
}
template<typename T, typename VST>
void travIn(BinNodePosition<T> x, VST& visit){
	Stack<BinNodePosition<T>> S;
	while(1){
		goLeftBranch(x, S);
		if(S.empty())
			break;
		x =S.top();
		S.pop();
		visit(x);
		x = x->rChild;
	}
}
