#include <cstring>
#include "calculator.h"

float add(float x, float y){
	return x+y;
}

float subtract(float x, float y){
	return x-y;
}

float multiply(float x, float y){
	return x*y;
}

float divide(float x, float y){
	return x/y;
}

float calculate(float x, float y, char * operations[], unsigned int size){
	
	float z=0;
	
	for(int i=0; i<size; i++){
		if(std::strncmp(operations[i], "add", strlen(operations[i]))==0){
			z+=add(x,y);
		
		}else if(std::strncmp(operations[i], "sub", strlen(operations[i]))==0){
			z+=subtract(x,y);
		
		}else if(std::strncmp(operations[i], "mul", strlen(operations[i]))==0){
			z+=multiply(x,y);
		
		}else if(std::strncmp(operations[i], "div", strlen(operations[i]))==0){
			z+=divide(x,y);
		}
	}
	
	return z;
	
}