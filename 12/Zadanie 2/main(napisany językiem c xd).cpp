#include <iostream>
#include <cstdlib>
#include <ctime>

#include "sort.h"

bool ascending1(double a, double b) {
    return a > b;
}

bool ascending2(double a, double b) {
    return a <= b;
}

int main(){
    double array1[1000];
    double array2[1000];
    double array3[1000];

    srand(time(NULL));

    for(int i = 0; i < 1000; i++) {
        array1[i] = rand();
        array2[i] = rand();
        array3[i] = rand();
    }

    printf("Before sorting:\n");
    printf("Array 1:\n");
    for(int i = 0; i < 1000; i++) {
        printf("%f ", array1[i]);
    }
    printf("\n");
    printf("Array 2:\n");
    for(int i = 0; i < 1000; i++) {
        printf("%f ", array2[i]);
    }
    printf("\n");
    printf("Array 3:\n");
    for(int i = 0; i < 1000; i++) {
        printf("%f ", array3[i]);
    }
    printf("\n");

    sorting::bubbleSort(array1, 1000, ascending1);
    sorting::quickSort(array2, 0, 999, ascending2);
    sorting::mergeSort(array3, 0, 999, ascending2);
    printf("After sorting:\n");
    printf("Array 1 (Bubble Sort):\n");
    for(int i = 0; i < 1000; i++) {
        printf("%f ", array1[i]);
    }
    printf("\n");
    printf("Array 2 (Quick Sort):\n");
    for(int i = 0; i < 1000; i++) {
        printf("%f ", array2[i]);
    }
    printf("\n");
    printf("Array 3 (Merge Sort):\n");
    for(int i = 0; i < 1000; i++) {
        printf("%f ", array3[i]);
    }
    return 0;
}