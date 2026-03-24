#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "sort.h"

bool ascending1(double a, double b) {
    return a > b;
}

bool descending1(double a, double b) {
    return a < b;
}

bool ascending2(double a, double b) {
    return a <= b;
}

bool descending2(double a, double b) {
    return a > b; 
}

int main() {
    double* array1 = new double[1000];
    double* array2 = new double[1000];
    double* array3 = new double[1000];


    std::srand(0);  

    for (int i = 0; i < 1000; ++i) {
        array1[i] = std::rand();
        array2[i] = std::rand();
        array3[i] = std::rand();
    }

    std::cout << "Before sorting:\n";

    std::cout << "Array 1:\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2:\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 3:\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;
    
    auto start1 = std::chrono::high_resolution_clock::now();
	for(int i=0; i<100; i++){
    sorting::bubbleSort(array1, 1000, ascending1);
    }
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
	for(int i=0; i<100; i++){
    sorting::quickSort(array2, 0, 999, ascending2);
    }
    auto end2 = std::chrono::high_resolution_clock::now();

    auto start3 = std::chrono::high_resolution_clock::now();
	for(int i=0; i<100; i++){
    sorting::mergeSort(array3, 0, 999, ascending2);
    }
    auto end3 = std::chrono::high_resolution_clock::now();

    std::cout << "After sorting:\n";

    std::cout << "Array 1 (Bubble Sort):\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 (Quick Sort):\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 3 (Merge Sort):\n";
    for (int i = 0; i < 1000; ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorting times:\n";
    std::cout << "Bubble Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " ns\n";
    std::cout << "Quick Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " ns\n";
    std::cout << "Merge Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count() << " ns\n";

    delete[] array1;
    delete[] array2;
    delete[] array3;

    return 0;
}