#include <iostream>

#include "calculator.h"

namespace {
	
	void quitWithError() {
		std::cout << "Invalid operation performed" << std::endl;
		exit(EXIT_FAILURE);
	}
	
} // anonymous namespace

// Place your definitions here

float add(float x, float y){
	float z = x+y;
	return z;
}

float subtract(float x, float y){
	float z = x-y;
	return z;
}

float multiply(float x, float y){
	float z = x*y;
	return z;
}

float divide(float x, float y){
	if(y==0){
		quitWithError();
	}
	
	float z = x/y;
	return z;
}

float calculate(Operation operation, float x, float y) {
    switch (operation) {
		
        case Operation::ADD:
            return add(x, y);
			
        case Operation::SUBTRACT:
            return subtract(x, y);
			
        case Operation::MULTIPLY:
            return multiply(x, y);
			
        case Operation::DIVIDE:
            return divide(x, y);
			
        default:
            quitWithError();
    }
}