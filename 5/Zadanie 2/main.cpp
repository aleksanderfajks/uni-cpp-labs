#include <iostream>
#include <cstring>
#include "convertCase.h"

#define tabSize 20

int main(){
	char tab[tabSize];
	
	std::cout << "Podaj " << tabSize << " znakow:" << std::endl;
	for(int j=0; j<tabSize; j++){
		std::cin >> tab[j];
	}
	
	convertCase(tab);
	
	std::cout << "Tablica po zamianie:" << std::endl;
	for(unsigned int i=0; i<tabSize; i++){
		std::cout << " " << tab[i];
	}
}