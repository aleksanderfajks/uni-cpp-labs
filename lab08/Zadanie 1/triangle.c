#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "triangle.h"

bool isRightTriangle(Point_t points[]){
	
	const double xValue1=points[1].x-points[0].x;
	const double yValue1=points[1].y-points[0].y;
	double distance1=sqrt(xValue1*xValue1+yValue1*yValue1);
	const double xValue2=points[2].x-points[0].x;
	const double yValue2=points[2].y-points[0].y;
	double distance2=sqrt(xValue2*xValue2+yValue2*yValue2);
	const double xValue3=points[2].x-points[1].x;
	const double yValue3=points[2].y-points[1].y;
	double distance3=sqrt(xValue3*xValue3+yValue3*yValue3);
	
	if(distance2>distance1){
		double a=distance2;
		distance2=distance1;
		distance1=a;
	}
	
	if(distance3>distance1){
		double b=distance3;
		distance3=distance1;
		distance1=b;
	}
	
	if(distance1*distance1==distance2*distance2+distance3*distance3){
		return true;
	} else{
		return false;
	}
	
}
