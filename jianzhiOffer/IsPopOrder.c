//Is the order the pop order of the push order
#include<stack>
bool IsPopOrder(const int* pPush, const int* pPop, int length){
	if(pPush==nullptr||pPop==nullptr||length<0)
		return false;
	Stack<int> pStack;
	pStack.push(*pPush);
	while(length!=0){
		while(*pPop!=pStack.top()){
			if(*pPush!='\0'){
				pStack.push(*(++pPush));
			}
			else
				return false;
		}
		pStack.pop();
		++pPop;
		--length;
	}
	if(pStack.empty()&&length==0)
		return true;
}
