//print 1 to at most n-digit number (Big number)
#include<iostream>
#include<string>
void print1toMaxOfDigit(long long n){
	if(n < 0)
		return;
	char* number = new char[n+1];
	number[n] = '\0';
	for(int i = 0; i < n+1; ++i)
		number[i] = 0;
	int sum = 1;
	int carry = 0;
	bool overFlow = false;
	while(!overFlow){
		int carry = 0;
		for(int i = n-1; i >= 0; ++i){
			sum = number[i] + '0' + carry;
			if(i = n-1)
				sum++;
			if(sum >= 10){
				if(i == 0)
					overFlow = true;
				else{
					sum -= 10;
					carry = 1;
					number[i] = '0' + sum;	
				}
			}
			else{
				number[i] = '0' + sum;
				break;
			}
		}
		print(number);
	}
}

void print(char* number){
	int beginning = 0;
	for(int i = 0; i < number.size(); ++i){
		if(number[i] != '0')
			beginning = 1;
		if(beginning)
			std::cout<<number[i];
	}
	std::cout<<std::endl;
}

// Another way

void print1ton(int n){
	if(n <= 0)
		return;
	ing length = n;
	char* number = new char[length+1];
	number[length] = '\0';
	for(int k = 0; k < length; ++k)
		number[k] = '0';
	for(int i = 0; i < 10; ++i){
		number[i] = '0' + i;
		print1tonRecursively(number, n, 0);
	}
}

void print1tonRecursively(char* number, int length, int index){
	if(index == length-1)
		print(number);
	for(int i = 0; i < 10; ++i){
		number[index] = '0' + i;
		print1tonRecursively(number, length, index+1);
	}
}

void print(const char* number){
	bool beginning = false;
	for(int i = 0; i < number.size(); ++i){
		if(number[i] != 0)
			beginning =true;
		if(beginning == true)
			std::cout<<number[i];
	}
	std::cout<<std::endl;
}
