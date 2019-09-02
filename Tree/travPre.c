//preorder traversal iteratively
#include"Tree.h"
#include<stack>
using namespace std;

template<typename T, typename VST>
void visitLeftBranch(BinNodePosition<T> x, VST& visit, Stack<BinNodePosition<T>>& S){
	while(x){
		S.puch(x->rChild);
		visit(x);
		x = x->lChild;
	}
}

template<typename T, typename VST>
void travPre(BinNodePosition<T> x, VST& visit){
	Stack<BinNodePosition<T>> S;
	while(1){
		visitLeftBranch(x, visit, S);
		if(!S.empty()){
			x = S.top();
			S.pop();
		}
		else
			break;
	}
}
