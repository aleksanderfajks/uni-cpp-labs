#include <iostream>
#include "arrayUtils.h"
#include <cstring>

char * resizeArray(char * array, unsigned int newSize){
	
	if (array == nullptr){
		return nullptr;
	}
	int oldSize = strlen(array);
	
	char *newArray = new char[newSize];
	if(oldSize<newSize){
		for (int i=0; i<oldSize; i++){
			newArray[i]=array[i];
		}
	}
	else{
		for (int i=0; i<newSize; i++){
			newArray[i]=array[i];
		}
	}
	
	delete[] array;
	return newArray;
}