#pragma once

namespace sorting {

/**
 * helper definition of a pointer to a function comparing two double-precision floating-point numbers
 * @return true if the numbers lhs and rhs meet the conditions defined by the function callback, false otherwise
 */
typedef bool (*Comparator)(double lhs, double rhs);

/**
 * sort array in ascending order using bubble sort algorithm
 * @param array pointer to array of double-precision floating-point numbers to be sorted
 * @param n size of array
 * @param comparator pointer to a function comparing two double-precision floating-point numbers:
 * use operator< to sort in descending order
 * use operator> to sort in ascending order
 */
void bubbleSort(double * array, unsigned int n, Comparator comparator);

/**
 * sort array in ascending using quick sort algorithm in indices range [lo, hi]
 * @param array pointer to array of double-precision floating-point numbers to be sorted
 * @param lo low index of array
 * @param hi high index of array
 * @param comparator pointer to a function comparing two double-precision floating-point numbers:
 * use operator> to sort in descending order
 * use operator<= to sort in ascending order
 */
void quickSort(double * array, int lo, int hi, Comparator comparator);

/**
 * sort array in ascending order using merge sort algorithm in indices range [lo, hi]
 * @param array pointer to array of double-precision floating-point numbers to be sorted
 * @param lo low index of array
 * @param hi high index of array
 * @param comparator pointer to a function comparing two double-precision floating-point numbers:
 * use operator> to sort in descending order
 * use operator<= to sort in ascending order
 */
void mergeSort(double * array, unsigned int lo, unsigned int hi, Comparator comparator);

} // namespace sorting
