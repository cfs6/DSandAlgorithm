#include<string>

int match(char* P, char* T){
	int *next = buildNext(P);
	sizt_t n = strlen(T), i = 0;
	size_T m = strlen(P), j = 0;
	while(i<n && j<m){
		if(j<0||P[j] == T[i]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
	delete []next;
	return i-j;//i-j<n-m 匹配成功返回匹配坐标;  i-j>n-m 匹配失败
}

int* buildNext(int* P){
	size_t m = strlen(P),j = 0;
	int* N = new int[m];
	int t = N[0] = -1;
	while(j<m-1){
		if(0>t||P[j]==P[t]){
			t++;j++;
			N[j] = (P[j]!=P[t]? t : N[t] );
		}
		else
			t = N[t];
	}
	return N;
}

