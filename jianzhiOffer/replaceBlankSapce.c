//replace the blank space ' ' in the string to '%20'

void replaceBlank(char string[], int length){
	if(string==nullptr||length<0)
		return;
	int blank_count, newLength;
	for(int i = 0; i <= length; i++){
		if(string[i]==' ')
			blank_count++;
	}
	newLength = length + 2 * blank_count + 1;
	int p1 = length;                 //p1: the end of the original string
	int p2 = newLength;              //p2: the end of the new string
	while(p2>0&&p2!=p1){
		while(string[p1]!=' '){
			string[p2] = string[p1];
			p1--;
			p2--;
		}
		p1--;
		string[p2--] = '0';
		string[p2--] = '2';
		string[p2--] = '%';
	}
}
