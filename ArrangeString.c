// 判断数组中的单词能否按首尾链接
// n:单词数目
// DFS
int ArrangeString(int n, char** num){
	if(n<0||*num==nullptr)
		return -1;
	char* str = new char[n+1];
	bool* visited = new bool[n];
	for(*str = *num; *str!='\0';++(*str)){
		arrange(*str);
	}

}

void arrange(int n, char* str){
	visited[*str] = true;
	for(;str!='\0';++str){
		if(canBelinked(str, ++str)&&visited[++str]==false)
			arrange(str)
	}
}

bool canBelinked(char* str1, char* str2){
	int len1 = strlen(str1);
	if(*(str1+len1-1) == *str2)
		return true;
	else
		return false;
}

char* nextStr(char* str){
		++str;
}

