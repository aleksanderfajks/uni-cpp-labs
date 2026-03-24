#include "math_utils.h"
#include <stdio.h>

int gcd(int x, int y){
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


int lcm(int x, int y){
    return (x / gcd(x, y)) * y;
}