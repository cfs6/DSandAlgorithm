//using backtracking to traverse inorder

template<typename T, typename VST>
void travIn(BinNodePosition<T> x, VST& visit){
	bool backtrack = false;
	while(1){
		if(!backtrack&&hasLChild(*x)){
			x = x->lChild;
		}
		else{
			visit(x);
			if(hasRChild(*x)){	
				x = x->rChild;
				backtrack = false;
			}
			else{
				if(!x = x->succ(x))
					break;
				backtrack = true;
			}
		}
	}
}

template<typename T>
BinNodePosition<T>  succ(BinNodePosition<T> x){
	if(hasrChild(x)){
		x = x->rChild;
		while(haslChild(x)){
			x = x->lChild;
		}
	}
	else{
		BinNodePosition<T> pNode;
		pNode = x;
		x = x->parent;
		while(x->lChild != pNode){
			pNode = x;
			x = x->parent;
		}
	}
	return x;
}
