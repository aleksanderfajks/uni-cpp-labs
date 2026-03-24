#include "defs.h"
#include <stdio.h>

//Deklaracja zmiennych typu zmienno przecinkowego pojedynczej precyzji
long long indeksStud1 = 287222;
long long indeksStud2 = 287334;

//Deklaracja funkcji
double avrage(long long firstNumber,long long secondNumber) {
	return (firstNumber + secondNumber)/2 ;
}

double printSize() {
	printf("Size of int: %d \n", sizeof(int));
	printf("Size of long long: %d \n", sizeof(long long));
	printf("Size of double: %d \n", sizeof(double));
	printf("Size of float: %d \n", sizeof(float));
	return (sizeof(int)+sizeof(float)+sizeof(long long)+sizeof(double));
}