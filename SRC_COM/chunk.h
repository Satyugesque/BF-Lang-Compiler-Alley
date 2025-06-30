#ifndef common_clox_h
#define common_clox_h
#include"common.h"
#include"value.h"

// defines a new name for pre existing dat types using typdef
typedef enum{
    OP_RETURN ,
    PRINT,
    KILL,
    RESURRECT,
    CLIMB,
    DIE ,
    OP_CONSTANT
} OpCode;



typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants;
    int* lines;
}Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk , uint8_t byte , int line);
int addConstant(Chunk* chunk, Value value);
#endif



