//Get the power of the number
//Consider all kinds of situations
bool invalidInput = false;
double power(double base, double exponent){
	if(base==0.0&&exponent<=0){
		invalidInput = true;
		return 0.0;	
	}
	double result = 1.0;
	if(exponent>0){
		while(exponent!=0.0){
			result *= base;
			--exponent;
		}
	}
	else if(exponent<0){
		exponent = -exponent;
		while(exponent!=0){
			result *= base;
			--exponent;
		}
		result = 1.0/result;
	}
	return result;
		
}

//Another way
bool inValidInput = false;
double Power(double base, double exponent){
	if(base == 0&&exponent<=0){
		inValidInput = true;
		return 0.0;
	}
	unsigned int absExponent;
	if(exponent<0)
		absExponent = (unsigned int)(-exponent);
	double result = powerWithUnsignedE(base, absExponent);
	if(exponent < 0)
		result = 1.0/result;
	return result;
}

double powerWithUnsignedE(double base, unsigned int exponent){
	if(exponent == 0)
		return 1.0;
	if(exponent == 1)
		return base;
	double result;
	result = powerWithUnsignedE(base, exponent>>1);
	result *= base;
	if(exponent & 0x1)
		result *=base;
	return result;
}
