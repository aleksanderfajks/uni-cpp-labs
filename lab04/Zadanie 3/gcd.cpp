#include <iostream>
#include "gcd.h"

int iterGcd(int x, int y){
	while(x!=0){
		unsigned int nwd = x;
		x=y%x;
		y=nwd;
	}
	return y;
}

int recurGcd(int x, int y){
	if(y!=0)
		return recurGcd(y, x%y);
}