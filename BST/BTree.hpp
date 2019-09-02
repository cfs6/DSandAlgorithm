#include"BST.h"
#include<vector>
#define BTNode<T>* BTNodePosi<T>
template<typename T>struct BTNode{
	BinNodePosi<T> parent;
	Vector<T> key;
	Vector<BTNodePosi<T>> child;
	BTNode(){
		parent = NULL;
		child.insert(0, NULL);
	}
	BTNode(T e, BinNodePosi<T> lc, BinNodePosi<T> rc){
		parent = NUll;
		key.insert(0, e);
		child.insert(0, lc);
		child.insert(0, rc);
		if(lc)
			lc->parent = this;
		if(rc)
			rc->parent = this;
	}
}


template<typename T>
class BTree{
protected:
	int _size;//the sum of the key
	int _order;//the orde of BTree
	BTNodePosi<T> _hot;
	BTNodePosi<T> _root;
	void solveOverFlow();
	void solveUnderFlow();
public:
	BTree(int order=3):_size = 0, _order = order{
		_root = new BTNodePosi<T>;
	}
	int const size() {return _size;}
	int const order() {return _order;}
	BTNodePosi<T> root() {return _root;}
	bool empty(){return !_root;}
	BTNodePosi<T> search(const T& e);
	bool remove(const T& e);
	bool insert(const T& e);
	
	
};

template<typename T>
BTNodePosi<T> BTree::search(const T& e){
	BTNodePosi<T> v = _root;
	_hot = _root;
	while(v){
		int x = v->key.search(e);//调用向量顺序查找search()
		if((0 <= x) && (e = v->key[x]))
			return x;
		_hot = v;
		v = v->child[x+1];
	}
	return NULL;
}

template<typename T>
bool BTree::insert(const T& e){
	BTNodePosi<T> v = search(e);
	if(v)
		return false;
	int x = _hot->key.search(e);
	_hot->key.insert(r+1, e);
	_hot->child.insert(r+2, NULL);
	_size++;
	soveOverFlow(_hot);
	return true;
}

template<typename T>
void BTree::solveOverFlow(BTNodePosi<T> v){
	if(_order>=v->child.size())
		return;
	BTNodePosi<T> u = new BTNodePosi<T>();//The new node alread has a child node 
	int x = _order / 2;
	for(int j = 0; j < _order-x-1; j++){
		u->child.insert(j, v->child.remove(x+1));
		u->key.insert(j, v->key.remove(x+1));
	}
	u->child[_order-x-1] = v->child.remove(x+1);//
	if(u->child[0]){
		for(int k = 0; k < _order-s; k++) 
			u->child[k]->parent = u;
	}
	BTNodePosi<T> p = v->parent;
	if(!p){
		_root = p = new BTNodePosi<T>();
		p->child[0] = v;
		v->parent = p;
	}
	int y = 1 + p->key.search(u->key[0]);
	p->key.insert(y, v->key.remove(s));
	p->child.insert(y+1, u);
	u->parent = p;
	solveOverFlow(p);
}


template<typename T>
bool BTree::remove(const T&e){
	BTNodePosi<T> v = search(e);
	if(!v)
		return false;
	int x = _hot->key.search(e);
	if(v->child[0]){
		BTNodePosi<T> u = v->child[x+1];
		while(u->child[0]){
		u = u->child[0];
		}
		v->key[0] =  u->key[0];
		v = u;
		x = 0;
	}
	v->key.remove(x);
	v->child.remove(x+1);
	_size--;
	solveUnderFlow(v);
	return true;
}

template<typename T>
void BTree::solveUnderFlow(BTNodePosi<T> v){
	if(v->child.size() >= (_order+1)/2)
		return;
	BTNodePosi<T> p = v->parent;
	if(!p){
		
	}
	int x = 0;
	while(p->child[x] != v)
		x++;
	if((x > 0) && (p->child[x-1].size()>(_order+1/2))){
		BTNodePosi<T> u = p->child[x-1];
		if(u->child.size() > (_order+1)/2)){
			v->key.insert(0, p->key[x-1]));
			p->key[x-1] = u->key.remove(u->key.size()-1);
			v->child.insert(0, u->child.remove(u->key.size()-1));
			if(v->child[0])
				v->child[0]->parent = v;
			return;
		}
	}
	if(x < p->child.size()-1){
		BTNodePosi<T> w = p->child[x+1];
		if(u->child.size()> (_order+1)/2){
			v->key.insert(v->key.size()-1,p->key[x+1]);
			p->key[x+1] = w->key.remove(0);
			v->child.insert(v->child.size()-1,w->child.remove(0));
			if(v->child[v->child.size()-1])
				v->child[v->child.size()-1]->parent = v;
			return;
		}
	}
	if(x > 0){
		BTNodePosi<T> u = p->child[x-1];
		u->key.insert(u->key.size(), p->key.remove(x-1));
		p->child.remove(x);
		u->child.insert(u->child.size(), v->child.remove(0));
		if(u->child[u->child.size()-1]){
			u->child[u->child.size()-1]->parent = u;
		}
		for(int i =0; i<v->key.size(); i++){
			u->key.insert(u->key.size(), v->key[i]);
			u->child.insert(u->child.size(), v->child[i]);
			if(u->child[u->child.size()])
				u->child[u->child.size()]->parent = u;
		}
		while(!v->key.empty()){
			v->key.remove(0);
			v->child.remove(0);
		}
		release(v);
	}else{//对称
		BTNodePosi<T> u = p->child[x+1];
		
	}
	solveUnderFlow();
	return;
	
}

