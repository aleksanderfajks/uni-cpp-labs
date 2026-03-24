#include <iostream>
#include "arrayUtils.h"

int main() {
	
	unsigned int tabSize=5;
	unsigned int lastSize;
	char *tab = new char[tabSize];

	std::cout << "Podaj pojedynczo znaki:" << std::endl;
	
	unsigned int i=0;
	while (true){
		
		if(i==tabSize){
			int newTabSize = tabSize +5;
			tab = resizeArray(tab, newTabSize);
			tabSize = newTabSize;
		}
		
		char x = std::cin.get();
		
		if (x == '\n') {
			continue;
		}
		
		tab[i] = x;
		
		if(i>0 && tab[i]==tab[i-1]){
			tab[i+1] = '\0';
			break;
		}
		i++;
	}
	
	std::cout << "Lancuch ma postac: ";
	
	for(int j=0; j<tabSize; j++){
		std::cout << tab[j];
	}
	
	delete[] tab;
	return 0;
}