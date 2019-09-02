//judge if it is a number
bool isNumeric(const char* str){
	if(str == nullptr)
		return false;
	int i = 0, dot;
	int dotCount = 0;
	int exe, exeCount = 0;
	while(str[i] != '\0'){
		if(str[i] == '.'){
			dot = i;
			dotCount += 1;
		}
		++i;
	}
	if(dotCount>1)
		return false;
	while(str[j]!='\0'){
		if(str[j] == 'e'||str[j] == 'E'){
			exe = j;
			++exeCount;
		}
		++j;	
	}
	if(exeCount > 1)
		return false;
	if(dot==str.size()||dot==0||exe==0||exe==str.size()||exe<=dot)
		return false;
	if(dotCount == 0){
		int j =0
		if(exeCount == 0){
			int k = 0;
			if(str[k]!='+'||str[k]!='-'||str[k]<'0'||str[k]>'9')
				returna false;
			while(str[k+1]!='\0'){
				if(str[k+1]<'0'||str[k+1]>'9')
					return false;
				++k;
			}
		}
		else{
			int m = 0;
			if(str[m]!='+'||str[m]!='-'||str[m]<'0'||str[m]>'9')
				returna false;
			while(m+1!=exe){
				if(str[m+1]<'0'||str[m+1]>'9')
					return false;
				++m;
			}
			if(str[m+2]!='+'||str[m+2]!='-'||str[m+2]<'0'||str[m+2]>'9')
				return false;
			while(str[m+3]!='\0'){
				if(str[m+3]<'0'||str[m+3]>'9')
					return false;
				++m;
			}
		}
	}
	else{
		if(exeCount == 0){
			
			if(dot == 0){
				int i = 1;
				while(str[i] != '\0'){
					if(str[i]<'0'||str[i]>'9')
						return false;
					++i;
				}
			}
			else{
				int j = 1;
				if(str[0]!='+'||str[0]!='-'||str[0]<'0'||str[0]>'9')
					return false;
				if(str[0]=='+' || str[0]=='+'){
					if(dot == 1)
						return false;
				}
				do{
					if(str[j]<'0'||str[j]>'9')
						return false;
					++j;
				}while(j != dot);
				++j;
				do{
					if(str[j]<'0'||str[j]>'9')
						return false;
					++j;
				}while(str[j]!='\0');
			}
		}
		eles{
			if(dot == 0){
				if(exe == 1)
					return false;
				int i = 1;
				while(i != exe){
					if(str[j] < '0'|| str>'9')
						return false;
					++i;
				}
				++i;
				while(str[i] != '\0'){
					if(str[i]<'0' || str[ i]>'9')
						return false;
					++i;
				}
			}
			else{
				int j = 1;
				if(str[0]!='+' || str[0]!='-' || str[0]<'0' || str[0]>'9')
					return false;
				if(str[0]=='-' || str[0]=='+'){
					if(dot == 1)
						return;
				}
				do{
					if(str[j]<'0' || str[j]>'9')
						return false;
					++j;	
				}while(j!=dot)
				++j;
				do{
					if(str[j]<'0' || str[j]>'9')
						return false;
					++j;
				}while(j!=exe)
				++j;
				while(str[j]!='\0'){
					if(str[j]<'0' || str[j]>'9')
						return false;
					++j;
				}
			}
	}
}

//Another way

bool numeric(char* str){
	 if(str==nullptr)
		 return false;
	 bool numeric = scanInteger(*str);
	 if(*str=='.'){
	 	++str;
		numberic = scanUnsignedteger(&str)||numeric;
	 }
	 if(*str=='e'|*str=='E'){
	 	++str;
		numberic = numeric&&scanInteger(&str);
	 }
	 return numberic&&*str=='\0';


}

bool scanInteger(char** str){
	if(**str=='+' || **str=='-')
		++(*str);
	return scanUnsignedInteger(str);
}

bool scanUnsignedInteger(char** str){
	const char* before = *str;
	while(**str>'0'&&**str<'9'&&**str!='\0')
		++(*str);
	return *str>before;
}
