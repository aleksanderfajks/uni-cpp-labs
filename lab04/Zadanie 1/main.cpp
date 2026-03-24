#include <iostream>
#include "multiply.h"

int main(){
	std::cout << "Mnozenie l. calkowitych = " << multiply(2, 3)
		<< std::endl;
	
	std::cout << "Mnozenie l. zmiennoprzecinkowych = " << multiply(5.1f, 3.2f)
		<< std::endl;
	
	std::cout << "Mnozenie l. rzeczywistych = " << multiply(45.0d, 24.2d)
		<< std::endl;
	
	return 0;
}