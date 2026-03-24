#include <iostream>
#include "fibonacci.h"

unsigned int fibonacci(unsigned int n) {
    if (n == 0){
        return 0;
    }

    if (n == 1) {
        return 1;
    }
    
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int result;

    for (unsigned int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}