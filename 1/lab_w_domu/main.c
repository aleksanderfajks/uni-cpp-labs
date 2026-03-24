#include <stdio.h>
#include "defs.h"

int main() {
	float result = add(x,y);
	printf("Addition result equals: %f \n", result);
	printf("Size of x: %d \n", sizeof (x));
	printf("Size of y: %d \n", sizeof (y));
	printf("Size of float: %d \n", sizeof (float));
	return 0;
}	