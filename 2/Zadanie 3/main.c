#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rsa_utils.h"
#include <stdbool.h>

int p;
int q;
int e;

int main () {
	
	srand (time( NULL));	//Ziarno generatora
	
	do {
		
		p = rand();		//Losuj liczbe p
		q = rand();		//Losuj liczbe q
		e = rand();		//Losuj liczbe e
		
	} while (isPrime(p)==isPrime(q)==false && gcd(e,p-1)==gcd(e,q-1)!=1);
	
	printf("Liczba p: %d \n", p);
	printf("Liczba q: %d \n", q);
	printf("Liczba e: %d \n", e);
	
	return 0;
}