#include <iostream>
#include "tabUtils.h"

void printTab(const int * const tab, unsigned int size){
	std::cout << "Zawartosc tablicy:";
	for(unsigned int i=0; i<size; i++){
		std::cout << " " << tab[i];
	}
	std::cout << std::endl;
}

void reverseTab(int * const tab, unsigned int size){
	unsigned int p=0;
	unsigned int k=size-1;
	
	while(p<k){
		int x=tab[p];
		tab[p]=tab[k];
		tab[k]=x;
		p++;
		k--;
	}
	std::cout << "Odwrocono tablice" << std::endl;
}

bool isPalindrome(int * const tab, unsigned int size){
	unsigned int p=0;
	unsigned int k=size-1;
	
	while(p<k){
		if(tab[p]!=tab[k]){
			return false;
		}
		p++;
		k--;
	}
	
	return true;
}