#include <stdio.h>
#include "conversion.h"

void decimalToBinary(unsigned int number){
	printf("Liczba %d w zapisie binarnym czytajac od gory to:", number);
	
	unsigned int n = 0;		//Zmienna przechowująca wartość liczby podanej binarnie
	int i=1;
	
	while(number>0){
		if(number%2==1){
			n=n+i;
		}
		
		number=number/2;
		i*=10;
		
	}
	printf("%d", n);
}