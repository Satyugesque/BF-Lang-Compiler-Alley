#include<stdio.h>
#include"common.h" 
#include"chunk.c"
#include"memory.c"
#include"debug.c"

#include"vm.c"
// debug.c already included value.c so it caused conflicts : I REALLY NEED TO FIGURE OUT LINKAGE PATTERNS : BIGGEST CONCERN OF NOW.

//#include"value.c" will cause redefinations A.




int main(int argc, const char* argv[])
{


  initVM();

    Chunk chunk;
    initChunk(&chunk);


 int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  printf("%d : OP_CODE  , %d : OP_LINE , %f : OP_CONSTANT\n " , (&chunk)->code[1], (&chunk)->lines[1] , (&chunk)->constants.values[0]);

  disassembleChunk(&chunk, "test chunk");

  freeVM();
  freeChunk(&chunk);
return 0;
}
// NEED TO FIGURE OUT PATH INCLUSION OF HEADERS. CREATE MAKEPATH:;
// The system is fully functional and working as expected.
// initChunk is the formost function to be called .