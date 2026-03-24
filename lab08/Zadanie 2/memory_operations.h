#pragma once

#include <cstddef>

#include "memory_sector.h"

INITIALIZE_MEMORY_SECTOR();

const unsigned int FENCE_INITIALIZER = 0xCAFEBABE;
const unsigned int BUFFER_INITIALIZER = 0xAB;

typedef enum address_status {
	NO_ERROR,
	ADDRESS_OUT_OF_RANGE
} address_status_t;

int * get_left_fence_address(memory_sector_t *);
int * get_right_fence_address(memory_sector_t *);

size_t get_memory_buffer_size(memory_sector_t *);

void initialize_memory(memory_sector_t *);

address_status_t validate_address(memory_sector_t * memory_sector, const int * address);

address_status_t read_memory(memory_sector_t *, const int * address, int * buffer);
address_status_t write_memory(memory_sector_t *, int * address, int value);
