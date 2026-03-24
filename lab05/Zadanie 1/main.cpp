#include <iostream>
#include "tabUtils.h"
#include <cstdlib>

#define tabSize 11

int main() {
	int tab[tabSize];
	for(int i=0; i<tabSize; i++){
		tab[i]=rand()%1000;
	}
	printTab(tab, tabSize);
	
	reverseTab(tab, tabSize);
	
	printTab(tab, tabSize);
	
	int p[] = {7,5,3,1,3,5,7};
	
	if(isPalindrome(p, 7)==true){
		std::cout << "Jest palindromem";
	} else{
		std::cout << "Nie jest palindromem";
	}
	
	return 0;
}