#include"BST.hpp"
template<typename T>
class RedBlack : public BST<T>{
public:
//	BinNodePosi<T> search(const T& e);  BST::search()
	BinNodePosi<T> insert(const T& e);
	bool remove(const T& e);
protected:
	void solveDoubleRed(BinNodePosi<T> x);
	void solveDoubleBlack(BinNodePosi<T> x);
	int updateHeight(BinNodePosi<T> x);
	
}

template<typename T>
int RedBlack<T>::updateHeight(BinNodeiPosi<T> x){
	x->height = max(stature(x->lc), stature(x->rc));
	if(IsBlack(x))
		x->height++;
	return x->height;
}

