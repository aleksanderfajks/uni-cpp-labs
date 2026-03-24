#include <iostream>
#include <chrono>
#include "gcd.h"

int main(){
	int z1=0;
	int z2=0;
	
	auto begin1 = std::chrono::high_resolution_clock::now();
	for(int i=0; i<1000000; i++) {
		z1 = iterGcd(4918, 512);
	}
	std::cout << "NWD iteracyjnie = " << iterGcd(4918, 512) << std::endl;
	auto end1 = std::chrono::high_resolution_clock::now();
	
	auto begin2 = std::chrono::high_resolution_clock::now();
	for(int i=0; i<1000000; i++) {
		z2 = recurGcd(4918, 512);
	}
	std::cout << "NWD rekurencyjnie = " << recurGcd(4918, 512) << std::endl;
	auto end2 = std::chrono::high_resolution_clock::now();
	
	auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-begin1).count();
	std::cout << "Czas wykonania funkcji iterGcd w nanosekundach = " << duration1 << std::endl;
	
	auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2-begin2).count();
	std::cout << "Czas wykonania funkcji recurGcd w nanosekundach = " << duration2 << std::endl;
	
	return 0;
}