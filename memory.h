#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)



#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)
    // Above , we again call upon reallocate, which we defined in memory.c, this time new size == 0;
       
    // We pass the size of old array by using its type and the number of instances of that type in that array.
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif