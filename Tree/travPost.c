//Postorder traverse iteratively
#include"Tree"
#include<stack>
using namespace std;

template<typename T, typename VST>
void gotoHeightestLeftLeaf(Stack<BinNodePosition<T>> S, BinNodePosition<T> x){
	while(x){
		S.push(x);
		if(hasLChild(x)){
			if(hasRChild(x)){
				S.push(x->rChild);
			}
			S.push(x->lChild);
			x = x->lChild;
		}
		else
			x = x->rChild;
	}
}

template<typename T, typename VST>
void travPost(BinNodePosition<T> x, VST& visit){
	Stack<BinNodePosition<T>> S;
	BinNodePosition<T> x;
	gotoHeightestLeftLeaf(S, x);
	while(!S.empty()){
		x = S.top();
		visit(x);
		S.pop();
		if(S.top()!=x->parent){
			x = S.top();
			gotoHeightestLeftLeaf(S, x);
		}
	}
}
