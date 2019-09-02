//Build a queue by 2 stack

#include<stack>
using namespace std;
template<typename T>
class CQueue{
public:
	CQueue();
	~CQueu();
	void appendTail(const T& node);
	T delTail();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue::appendTail(const T& node){
	if(stack1.full())
		return 0;
	stack1.push(node);
}
template<typename T>
T CQueue::delTail(){
	if(stack2.empty()){
		if(stack1.empty())
			return 0;
		else{
			while(!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
	}
	T node = stack2.top();
	stack2.pop();
	return node;
}

