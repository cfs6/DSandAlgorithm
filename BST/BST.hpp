#include<stdio.h>
#include<stdlib.h>

template<typename T>class BST:public BinTree{
public:
	virtual BinNodePosition<T>& search(const T&);
	virtual BinNodePosition<T> insert(const T&);
	virtual bool remove(const T&);
protected:
	BinNodePosition<T> _hot;
	BinNodePosition<T> connect34{
		BinNodePosition<T>,BinNodePosition<T>,BinNodePosition<T>,BinNodePosition<T>,BinNodePosition<T>,BinNodePosition<T>,BinNodePosition<T>
	}
	BinNodePosition<T> rotateAt(BinNodePosition<T>);	
};

template<typename T>
BinNodePosition<T>& BST<T>::search(const T& e){
	return searchIN(root, e, hot=NULL);
}
//尾递归BSTsearch()
template<typename T>
static BinNodePosition<T> searchIN(BinNodePosition<T>& v, const T& e, BinNodePosition<T>& hot){
	if(!v||v->data==e)
		return v;
	hot = v;
	return searchIN((v->data>e?v->lChild,v->rChild), e, hot); 
}

//迭代BSTsearch()
static BinNodePosition<T> searchIN(BinNodePosition<T>& v,const T& e, BinNodePosition<T>& hot){
	while(v||v->data!=e){
		hot = v;
		v = v->data>e?v->lChild,c->rChild;
	}
	return v;
}

template<typename T>
BinNodePosition<T> BST<T>::insert(const T& e){
	BinNodePosition<T> &x = search(e);
	if(!x){
		x = new BinNodePosition<T>(e, hot);//以hot 为父亲
		size++;
		updateHeight();
	}
	return x;
}

template<typename T>
bool BST<T>::remove(const T&e){
	BinNodePosition<T> &x=search(e);
	if(!x)
		return false;
	removeAt(x,hot);
	size--;
	updataHeight(hot);
	return true;
}

template<typename T>
bool BinNodePosition<T> removeAt(BinNodePosition<T> &x,BinNodePosition<T> hot){
	BinNodePosition<T> w = x;
	BinNodePosition<T> succ = NULL;
	if(!hasLChild(*x))
		succ = x = x->rChlid;
	else if(!hasRChild(*x))
		succ = x = x->lChild;
	else{
		w=succ(x);
		swap(x->data, w->data);
		BinNodePosition<T> u = w->parent;
		(u==x?w->rChild,u->lChild) = succ = w->rChild;
	}
	hot = w->parent;
	if(succ)
		succ->parent = hot;
	release(w->data);
	release(w);
	return succ;
}


template<typename T>
BinNodePosition<T> BST<T>::connect34(BinNodePosition<T> a, BinNodePosition<T> b, BinNodePosition<T> c, 
									 BinNodePosition<T> T0, BinNodePosition<T> T1, BinNodePosition<T> T2, BinNodePosition<T> T3){
	a->lChild = T0;
	if(T0)
		T0->parent = a;
	a->rChild = T1;
	if(T1)
		T1->parent = a;
	updateHeight(a);
	c->lChild = T2;
	if(T2)
		T2->parent = c;
	c->rChild = T3;
	if(T3)
		T3->parent = c;
	updateheight(c);
	b->lChild = a;
	a->parent = b;
	b->rChild = c;
	c->parent = b;
	updateHeight(b);
	return b;
	
}



















