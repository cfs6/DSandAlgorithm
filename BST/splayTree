#include"BST.h"
#include<stdio.h>

#define BinNodePosition BinNodePosi
#define lc LChild
#define rc RChild
template<typename T>
class Splay:public BST<T>{
protected:
	BinNodePosi<T> Splay(BinNodePosition<T> v);
public:
	BinNodePosi<T> &search(const T& e);
	BinNodePosi<T> insert(const T& e);
	bool remove(const T& e);
}
template<typename T> inline
void attachAsLChild(BinNodePosi<T> p,BinNodePosi<T> lc){
	p->lChild = lc;
	if(lc)
		lc->parent = p;
}

template<typename T> inline
void attachAsRChild(BinNodePosi<T> g,BinNodePosi<T> rc){
	g->rChild = rc;
	if(rc)
		rc->parent = g;
}

template<typename T>
class Splay::splay(BinNodePosi<T> v){
	if(!v)
		return NULL;
	BinNodePosi<T> p;
	BinNodePosi<T> g;
	while((p = v->parent)&&(g = p->parent)){
		BinNodePosi<T> gg = g->parent;
		if(IsLChild(*v)){
			if(IsLchild(*p)){
				attachAsLChild(g, p->rc);
			    attachAsLChild(p, v->rc);
			    attachAsRChild(p, g);
			    attachAsRChild(v, p);
			}
			else{
				attachAsLChild(p, v->rc);
				attachAsRChild(g, v->lc);
				attachAsRChild(v, p);
				attachAsLChild(v, g);
			}
		}
		else IsRChild(*v)){
			if(IsRChild(*p)){
				attachAsRChild(p, v->rc);
				attachAsRChild(g, p->lc);
				attachAsLChild(v, p);
				attachAsLChild(p, g);
			}
			else{
				attachAsRChild(p, v->lc);
				attachAsLChild(v, p);
				attachAsLChild(g, v->rc);
				attachAsRChild(v, g);
			}
		}
		if(!gg){
			v->parent = NULL;
		}
		else{
			g == gg->LChild?attachAsLChild(gg, v):attachAsRChild(gg, v);
		}
		updateHeight(g);
		updateHeight(p);
		updateHeight(v);
	}
	if(p = v->parent){
		if(isLChild){
			attachAsLChild(p, v->rc);
			attachAsRChild(v, p);
		}
		else{
			attachAsRChild(p, v->lc);
			attachAsLChild(v, p);
		}
			
	}
	v->parent = NULL;
	return v;
}

template<typename T>
BinNodePosi<T> &Splay<T>::search(const T& e){
	BinNodePosi<T> p = searchIN(root, e, hot = NULL);
	root = splay(p?p:hot);
	return root;
}

template<typename T>
BinNodePosi<T> Splay<T>::insert(const T& e){
	BinNodePosi<T> p = searchIN(root, e, hot = NULL);
	
}








