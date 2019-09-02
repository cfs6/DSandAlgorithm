//grep match: '.' and '*'
enum pType{Dot, Asterisk, Nop}
bool grepMatch(char* str,char* pattern){
	if(str == nullptr||pattern == nullptr)
		return false;
	int i,j;
	pType patternType = Nop;
	for(i = 0; i < pattern.size(); ++i){
		if(str[i] == '.')
			patternType = Dot;
	}
	for(j = 0; j < pattern.size(); ++j){
		if(str[j] == '*')
			patternType = Astetisk;
	}
	if(pattern == Nop)
		return false;
	if(patternType == Dot){
		int m = 0;
		while('.' != pattern[m]){
			if(pattern[m] == str[m])
				++;
			else
				return false;
		}
		m++;
		while(pattern[m] != '\0'){
			if(pattern[m] == str[m])
				++m;
			else
				return false;
		}
	}
	if(patternType == Asterisk){
		int k = 0;
		int q;
		while(pattern[k] != '*'){
			k++;
		}
		for(int p = o; p < k-1; ++p){
			if(str[p] != pattern[i])
				return false;
		}
		if(str[k-1] == pattern[k-1]){
			for(int q = k; str[q] != pattern[k+1]; ++q){}
			int m = k;
			while(m != q){
				if(pattern[k-1] != str[m])
					return false;
				++m;
			}
		}
		if(str[k-1] != pattern[k-1]){
			int k2 = k+1;
			while(str[k-1] != '\0'||pattern[k2] != '\0'){
				++k;
				++k2;
			}
		}
	}
	return true;
}


//Another way

bool match(char* str, char* pattern){
	if(str == nullptr||pattern == nullptr)
		return false;
	return matchCore(str, pattern);
}

bool matchCore(char* str, char* pattern){
	if(*str == '\0'&&*pattern =='\0')
		return true;
	if(*str != '\0'&&pattern == '\0')
		return false;
	if(*(pattern+1) == '*'){
		if(*pattern == *str||(*pattern == '.'&&*str!='\0')){
			return matchCore(str+1, pattern)||matchCore(str+1, pattern+2)||matchCore(str, pattern+2);
		}
		else
			return matchCore(str, pattern+2);
	}
	if(*str == *pattern||(*pattern == '.'&&str!='\0'))
		return matchCore(str+1, pattern+1);

	return false;
}
