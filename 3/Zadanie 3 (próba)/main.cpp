#include <iostream>

#include "calculator.h"

int main() {
	
	while(0<1){
		float x, y, result;
		float x1=x;
		float y1=y;
		std::cout << "Type two numbers." << std::endl << "x: ";
		std::cin >> x;
		std::cout << std::endl << "y: ";
		std::cin >> y;
		if(x1==x && y1==y){
			std::cout << "Wprowadzono ta sama kombinacje liczb dwa razy.";
			return EXIT_SUCCESS;
		}
		std::cout << std::endl << "Choose arithmetic operation to be performed:" << std::endl
			<< "0 - addition" << std::endl
			<< "1 - subtraction" << std::endl
			<< "2 - multiplication" << std::endl
			<< "3 - division" << std::endl;
		unsigned int operationValue;
		std::cin >> operationValue;
		Operation operation = static_cast<Operation>(operationValue);
		result = calculate(operation, x, y);
		std::cout << "Operation result equals: " << result << std::endl;
	}
	
	return EXIT_SUCCESS;
}