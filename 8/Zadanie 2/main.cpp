#include <cassert>
#include <cstdlib>
#include <iostream>

#include "memory_operations.h"

int main() {
	// 1. Initialize memory sector
	memory_sector_t memory_sector;
	initialize_memory(&memory_sector);

	// 2. Validate initialization
	int buffer = 0;

	// 2a. Validate left fence
	assert(read_memory(&memory_sector, get_left_fence_address(&memory_sector), &buffer) == NO_ERROR);
	assert(buffer == FENCE_INITIALIZER);

	// 2b. Validate memory buffer
	for (int * address = get_left_fence_address(&memory_sector) + 1; address < get_right_fence_address(&memory_sector); ++address) {
		assert(read_memory(&memory_sector, address, &buffer) == NO_ERROR);
		assert(buffer == BUFFER_INITIALIZER);
	}

	// 2c. Validate right fence
	assert(read_memory(&memory_sector, get_right_fence_address(&memory_sector), &buffer) == NO_ERROR);
	assert(buffer == FENCE_INITIALIZER);

	// 2d. Read value out of range
	buffer = 0;
	assert(read_memory(&memory_sector, get_right_fence_address(&memory_sector) + 1, &buffer) == ADDRESS_OUT_OF_RANGE);
	assert(buffer == 0);

	// 2e. Write first and last buffer field
	int value = 0xDD;
	assert(write_memory(&memory_sector, get_left_fence_address(&memory_sector) + 1, value) == NO_ERROR);
	assert(read_memory(&memory_sector, get_left_fence_address(&memory_sector) + 1, &buffer) == NO_ERROR);
	assert(buffer == value);

	assert(write_memory(&memory_sector, get_right_fence_address(&memory_sector) - 1, value) == NO_ERROR);
	assert(read_memory(&memory_sector, get_right_fence_address(&memory_sector) - 1, &buffer) == NO_ERROR);
	assert(buffer == value);

	std::cout << "All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
