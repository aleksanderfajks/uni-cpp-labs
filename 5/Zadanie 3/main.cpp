#include <iostream>
#include <cstring>
#include "calculator.h"

int main(int argc, char **argv){
	
	float x;
	float y;
	
	std::cout << "Podaj liczbe x: ";
	std::cin >> x;
	std::cout << std::endl << "Podaj liczbe y: ";
	std::cin >> y;
	
	std::cout << std::endl << "Wynik funkcji = " << calculate(x, y, argv, argc);
	
	return 0;
}