#include <stdio.h>

#include "math_utils.h"

int main(){
    int x;
    int y;

    printf("Podaj liczbe calkowita x: ");
    scanf("%d", &x);
    printf("Podaj liczbe calkowita y: ");
    scanf("%d", &y);

    printf("Najwiekszy wspolny dzielnik %d i %d to: %d\n", x, y, gcd(x, y));
    printf("Najmniejsza wspolna wielokrotnosc %d i %d to: %d\n", x, y, lcm(x, y));
	
	return 0;
}