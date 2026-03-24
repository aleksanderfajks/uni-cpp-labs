#include "fib.h"

int fibonacci(unsigned int n) {
	if (n < 2)
		return n;
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
}

int itterFibonacci(unsigned int x) {
	int a=1;
	int b=1;
	for(int i=2; i<x; i++){
		int y=b;
		b=a+b;
		a=y;
	}
	
	return b;
}