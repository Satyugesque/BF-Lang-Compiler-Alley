"# BF-Lang-Compiler-Alley" 

## Project Structure

This project is a simple compiler and virtual machine for the Lox based BF programming language. The source code is organized into several key components:

*   **`main.c`**: The main entry point of the application. It drives the compilation and execution process, tying together the different modules of the compiler pipeline.

*   **`chunk.c` / `chunk.h`**: This module is responsible for managing dynamic arrays of bytecode, referred to as "chunks".
    *   `chunk.h` defines the `Chunk` struct and other core data structures.
    *   `chunk.c` implements functions to initialize, write to, and free these chunks.

*   **`debug.c` / `debug.h`**: Contains debugging facilities for the compiler. It includes functions to disassemble bytecode chunks and instructions, printing them in a human-readable format to aid in development and verification.
