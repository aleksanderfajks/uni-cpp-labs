#include <cstring>

#include <iostream>

#include "sort.h"

namespace sorting {
	
namespace {
	
void swap(double * a, double * b) { 
    double tmp = *a; 
    *a = *b; 
    *b = tmp;
}

int partition(double * array, int lo, int hi, Comparator comparator) {
    double pivot = array[hi];
    int pivotIdx = lo;
    for (unsigned int i = lo; i < hi; ++i) {
        if (comparator(array[i], pivot)) {
            swap(array + i, array + pivotIdx);
			++pivotIdx;
        }
    }
    swap(array + hi, array + pivotIdx); 
    return pivotIdx; 
}

void merge(double * array, unsigned int lo, unsigned int mi, unsigned int hi, Comparator comparator) {
	const unsigned int tabSize = hi + 1;
	double arrayCopy[tabSize];
	std::memcpy(arrayCopy, array, sizeof(double) * tabSize);
	
	unsigned int iterator = lo;
	unsigned int loIterator = lo;
	unsigned int hiIterator = mi + 1;
	while (loIterator <= mi && hiIterator <= hi)
		if (comparator(arrayCopy[loIterator], arrayCopy[hiIterator]))
			array[iterator++] = arrayCopy[loIterator++];
		else
			array[iterator++] = arrayCopy[hiIterator++];
	
	while (loIterator <= mi)
		array[iterator++] = arrayCopy[loIterator++];
	
	while (hiIterator <= hi)
		array[iterator++] = arrayCopy[hiIterator++];
}
	
} // anonymous namespace

void bubbleSort(double * array, unsigned int n, Comparator comparator) {
    if (array) {
        bool wasSwapped = false;
        for (unsigned int i = 0; i < n - 1; ++i) {
            for (unsigned int j = 0; j < n - i - 1; ++j)  
                if (comparator(array[j], array[j + 1])) {
                    swap(array + j, array + j + 1);
                    wasSwapped = true;
                }
            if (!wasSwapped)
                break;
        }
    }
}

void quickSort(double * array, int lo, int hi, Comparator comparator) {
	if (array && hi > lo) {
        int pivotIdx = partition(array, lo, hi, comparator);
        quickSort(array, lo, pivotIdx - 1, comparator);
        quickSort(array, pivotIdx + 1, hi, comparator);
    }
}

void mergeSort(double * array, unsigned int lo, unsigned int hi, Comparator comparator) {
	if (array && hi > lo) {
        unsigned int mi = (lo + hi) / 2;
        mergeSort(array, lo, mi, comparator);
        mergeSort(array, mi + 1, hi, comparator);
        merge(array, lo, mi, hi, comparator);
    }
}

} // namespace sorting
