#include <stdlib.h>
#include <stdio.h>
#include "debug.h"
#include "value.c"

void disassembleChunk(Chunk *chunk, const char *name)
{
    printf("== %s ==\n", name);
    for (int offset = 0; offset < chunk->count;)
    {
        offset = disassembleInstruction(chunk, offset);
    }
}
static int simpleInstruction(const char *name, int offset)
{
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char *name, Chunk *chunk, int offset)
{
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d ", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("\n");
    return offset + 2;
    // +2 because +1 is also occupied by 0th instruction's loaded data. So effectively, new instruction is stored in +2.
}
// OP_RETURN IS THE HOLDER FOR INSTRUCTIONS . . . OR COMAMNDS USER MAY
int disassembleInstruction(Chunk *chunk, int offset)
{
    printf("%d = offset number  \n ", offset);

    if (offset > 0 &&
        chunk->lines[offset] == chunk->lines[offset - 1])
    {
        printf("   | ");
    }
    else
    {
        printf("%4d ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction)
    {
    case OP_RETURN:
        return simpleInstruction("OP_RETURN", offset);
        break;
    case PRINT:
        return simpleInstruction("PRINT", offset);
        break;
    case KILL:
        return simpleInstruction("KILL", offset);
        break;
    case RESURRECT:
        return simpleInstruction("RESURRECT", offset);
        break;
    case CLIMB:
        return simpleInstruction("CLIMB", offset);
        break;
    case DIE:
        return simpleInstruction("DIE", offset);
        break;
    case OP_CONSTANT:
        return constantInstruction("OP_CONSTANT", chunk, offset);
        break;

    default:
        printf(" ERROR : Unknown opcode %d\n", instruction);
        // exit(1);
        return offset + 1;
        break;
    }
}