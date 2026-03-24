#include "rsa_utils.h"
#include <stdbool.h>
#include <math.h>

int gcd(unsigned int x, unsigned int y){	//Funkcja szukajaca NWD podanych liczb wykorzystując algorytm Euklidesa
	while(x!=0){
		unsigned int nwd = x;
		x=y%x;
		y=nwd;
	}
	return y;
}

bool isPrime(unsigned int x){ 	//Funkcja sprawdzająca czy dana liczba jest pierwsza
	
	bool result=true;
	
	if(x<=1){
		
		result=false;	//Liczba 1 nie jest liczbą pierwsza, dlatego go wykluczamy
	
	} else {
		
		for(int i=2; i<x; i++){		//Pętla która sprawdza czy istnieje taka liczba z zakresu od 2 do podanej liczby, która
			
			if(x%i==0){				//jest dzielnikiem podanej przez nas liczby i jeśli jest to zwraca wartoś fałszywą
				result=false;
			} 
		}	
	}
	return result;
}