#include<iostream.h>
const int DefaultSize = 100;
template<class E, class K>
struct SkipNode{
	E data;
	SkipNode** link;
	SkipNode(int size = DefaultSize){
		SkipNode** link = new SkipNode<E,K>* [size];
		if(link == nullptr){
			cerr<<"pointer array failed!"<<endl;
			exit(1);
		}
	}
	~SkipNode(){delete[] link;}	
};

template<class E, class K>
class SkipList{
	SkipList(K large, int maxlev = DefaultSize);
	~SkipList();
	bool Search(const K k1, E& el)const;
	E& getData(SkipNode<E, K> *current) {
		if(current!=nullptr){
			return &current->data;
		}
		else
			return nullptr;
	}
	bool Insert(K kl, E el);
	bool Remove(K kl, E el);
private:
	int maxLevel;
	int level;
	K tailKey;
	SkipNode<K,E> *header;
	SkipNode<K,E> *tail;
	SkipNode<K,E> **last;
	int level();
	SkipList* saveSearch(const K kl);
}
template<class E,class K>
SkipList<E,K>::SkipList(K large, int maxLev){
	maxLevel = maxlev;
	level = 0;
	tailKey = large;
	SkipNode<K,E> *header = new SkipNode[maxLevel+1];
	SkipNode<K,E> *tail = new SkipNode[0];
	SkipNode<K,E> *last = new SkipNode*[maxLevel+1];
	tail->data = large;
	for(int i = 0; i < maxLevel+1; ++i){
		header->link[i] = tail;
	}
}

template<class E,class K>
SkipList<E,K>::~SkipList(){
	SkipNode<E,K> *next;
	while(header != tail){
		next = header->link[0];
		delete header;
		header = next;
	}
	delete tail;
	delete []last;
}

template<class E,class K>
bool SkipList<E,K>::Search(const K k1, E& el){
	if(kl > tail)
		return false;
	SkipNode* pNode = header;
	for(i = level; i > 0; --i){
		while(pNode->link[i]->data < kl)
			pNode = pNode->link[i];
	}
	el = p->link[0]->data;
	return (el==kl)?true:false;
}

template<class E,class K>
SkipList<E,K>* SkipList::saveSearch(const K k1){
	if(kl>tail)
		return;
	SkipNode* pNode = header;
	for(i = level; i > 0; --i){
		while(pNode->link[i]->data < kl){
			pNode = pNode->link[i];
		}
		last[i] = pNode;
	}
	return pNode->link[0]
}

template<class E,class K>
int SkipList<E,K>::level(){
	int lev = 0;
	while(rand()<RAND_MAX/2)
		lev++;
	return (lev<maxLevel)?lev:maxLevel;
}

template<class E,class K>
bool SkipList<E,K>::Insert(K kl, E el){
	if(kl>tail)
		return false;
	SkipNode* pNode = saveSearch(kl);
	if(kl == el)
		return false;
	int lev = level();
	if(lev > maxLevel){
		lev = ++maxlevel;
		last[lev] = header;
	}
	SkipNode* newNode = new SkipNode<E,K>[lev+1];
	newNode->data = kl;
	for(int i = 0; i < lev+1; ++i){
		newNode->link[i] = last->link[i];
		last->link[i] = newNode;
	}

	return true;
}
template<class E, class K>
bool SkipList<E,K>::Remove(K kl, E el){
	if(kl>tail)
		return false;
	SkipNode* pNode = saveSearch(kl);
	if(pNode->data!=el)
		return false;
	for(int i = 0; i < level&&last[i]->link[i]==pNode; ++i){
		last[i]->link[i] = pNode->link[i];
	}
	while(level>0 && header->link[level]==tail)
		level--;
	return true;
}

