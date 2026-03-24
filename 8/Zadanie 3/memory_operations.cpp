#include "memory_sector.h"
#include "memory_operations.h"
#include <cstring>
#include <cstddef>

int * get_left_fence_address(memory_sector_t *memory_sector){
	return &(memory_sector->l_fence);
}

int * get_right_fence_address(memory_sector_t *memory_sector){
	return &(memory_sector->r_fence);
}

size_t get_memory_buffer_size(memory_sector_t * memory_sector){
	return &(memory_sector->r_fence) - &(memory_sector->l_fence)-1;
}

void initialize_memory(memory_sector_t *memory_sector){
	memory_sector->l_fence = FENCE_INITIALIZER;
	memory_sector->r_fence = FENCE_INITIALIZER;
	
	size_t size = &(memory_sector->r_fence) - &(memory_sector->l_fence) -1;
	for(size_t i=0; i<size; i++){
		memory_sector->buffer[i] = BUFFER_INITIALIZER;
	}
}

address_status_t validate_address(memory_sector_t * memory_sector, const int * address){
	int* start = &(memory_sector->l_fence);
    int* end = &(memory_sector->r_fence);
	
	if (address < start || address > end) {
        return ADDRESS_OUT_OF_RANGE;
    }
	
    return NO_ERROR;
}

address_status_t read_memory(memory_sector_t *memory_sector, const int * address, int * buffer){
	if (validate_address(memory_sector, address) == ADDRESS_OUT_OF_RANGE) {
        return ADDRESS_OUT_OF_RANGE;
    }

    *buffer = *address;
    return NO_ERROR;
}
	
address_status_t write_memory(memory_sector_t* memory_sector, int* address, int value) {
    if (validate_address(memory_sector, address) == ADDRESS_OUT_OF_RANGE) {
        return ADDRESS_OUT_OF_RANGE;
    }

    *address = value;
    return NO_ERROR;
}

//Zadanie 3
address_status_t copy_memory(memory_sector_t *memory_sector, int *destination, int * source, size_t size){
	for (size_t i=0; i<size; i++){
        if (validate_address(memory_sector, destination + i)==ADDRESS_OUT_OF_RANGE){
            return ADDRESS_OUT_OF_RANGE;
        }
    }
	
	std::memcpy(destination, source, size*sizeof(int));
	return NO_ERROR;
}