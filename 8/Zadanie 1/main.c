#include <stdio.h>
#include <stdbool.h>
#include "triangle.h"

int main(){
	Point_t points[3];
	
	printf("Podaj wspolrzedna x pierwszego punktu: ");
	scanf("%lf", &points[0].x);
	printf("Podaj wspolrzedna y pierwszego punktu: ");
	scanf("%lf", &points[0].y);
	printf("Podaj wspolrzedna x drugiego punktu: ");
	scanf("%lf", &points[1].x);
	printf("Podaj wspolrzedna y drugiego punktu: ");
	scanf("%lf", &points[1].y);
	printf("Podaj wspolrzedna x trzeciego punktu: ");
	scanf("%lf", &points[2].x);
	printf("Podaj wspolrzedna y trzeciego punktu: ");
	scanf("%lf", &points[2].y);

	if(isRightTriangle(points)){
		printf("Trojkat zlozony z podanych punktow jest prostokatny.");
	} else{
		printf("Trojkat zlozony z podanych punktow nie jest prostokatny.");
	}
	
	return 0;
	
}