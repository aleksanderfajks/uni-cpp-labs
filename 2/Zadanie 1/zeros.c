#include "zeros.h"
#include <math.h>
#include <stdio.h>

void zeros(float a, float b, float c){
	
	if(a==0){	//Sprawdzenie czy funkcja jest kwadratowa
		printf("Wspolczynnik a nie moze byc rowny 0");
	} else{
		float d=b*b-4*a*c;
		
		if(d>0){	//Dla delty dodatniej
			float x1=(-b-sqrt(d))/(2*a);	//Liczenie pierwszego miejsca zerowego
			float x2=(-b+sqrt(d))/(2*a);	//Liczenie drugiego miejsca zerowego
			printf("Pierwsze miejsce zerowe to: %f \n", x1);
			printf("Drugie miejsce zerowe to: %f \n", x2);
		} else if (d==0){	//Dla delty = 0
			x1=-b/(2*a);
			printf("Jedno miejsce zerowe to: %f \n", x1);
		} else{	//Dla delty ujemnej
			printf("Nie ma zadnych miejsc zerowych");
		}
	}	
}