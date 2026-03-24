#pragma once

#define DECLARE_MEMORY_SECTOR(sector_size) \
typedef struct memory_sector {             \
	int l_fence;                           \
	int buffer[sector_size];               \
	int r_fence;                           \
} memory_sector_t;

#define RAND_SECTOR_SIZE 10 + ((int)__TIME__[6] + (int)__TIME__[7]) % 11
#define INITIALIZE_MEMORY_SECTOR() DECLARE_MEMORY_SECTOR(RAND_SECTOR_SIZE)
