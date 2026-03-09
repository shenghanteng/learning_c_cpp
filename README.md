# Learning C/C++

## Table of contents
- [Program structure](#Program-structure)
- [Compilation & execution](#Compilation--execution)
- [Data types & memory size](#Data-types--memory-size)
- [Strings & special characters](#Strings--special-characters)
- [Array](#Array)
- [Data structure & algorithms](#Data-structures--algorithms)
- [Conditional statements](#Conditional-statements)
- [Libraries](#Libraries)
- [Resources](#Resources)
- [References](#References)

## Program structure
- Preprocessor directives & header files
    - Standard libraries
        - `#include <LIBRARY.h>`
    - User-defined libraries
        - `#include "LIBRARY.h"`
        - In `LIBRARY.h`
            ```c
            #ifndef LIBRARY_H // if not defined
            #define LIBRARY_H
            ...
            #endif
            ```
    - User-define variables
        - `#define VARIABLE VALUE`
- Function prototypes (declarations)
    - `RETURN_TYPE FUNCTION_NAME(TYPE VARIABLE, ...);`
- The main function
    - `int main(void){...; return (0);}`
        - Returns an integer, takes zero arguments
    - `int main(int argc, char **argv){...;}`
        - Returns an integer, takes command-line arguments
- Function definitions
    ```c
    RETURN_TYPE FUNCTION_NAME(PARAMETERS, ...)
    {
        ...;
        return VALUE; // in RETURN_TYPE
    }
    ```
- Comments
    - `// single-line comments`
    - `/* multi-line comments */`
- Example
    ```c
    /* This is a C program that
    prints "Hello World!" 
    to the screen. */
    #include <stdio.h>
    
    void print(char *str);
    
    int main(void)
    {
        print("World"); // Hello World!
        return (0);
    }
    
    void print(char *str)
    {
        printf("Hello %s!\n", str);
    }
    ```

## Compilation & execution
- Program compilation
    - Compilers: `cc`, `gcc`
    - `gcc PROGRAM.c` -> `a.out` (binary file)
    - `gcc PROGRAM.c -o PROGRAM` -> `PROGRAM` (binary file)
- Program execution
    - `./a.out` (or `./PROGRAM`)
    - Exit codes
        - 0: success
        - 1-255: failure
            - 127: command not found
            - 130: terminated, e.g., Ctrl-C
        - In terminal: `echo $?`
    - Command-line arguments
        - In program with `int main(int argc, char **argv){...;}` or `int main(int argc, char *argv[]){...;}`
            - `argc`: argument count (always >= 1)
            - `argv`: argument vector (array)
            - `argv[argc]`: `NULL`
        - Example
            - In terminal: `./a.out one two`
            - `argc`: 3 (1 program name + 2 parameters)
            - `argv[0]`: `"./a.out"`
            - `argv[1]`: `"one"`
            - `argv[2]`: `"two"`

## Data types & memory size
- Syntax
    - `TYPE VARIABLE = VALUE;`
- Memory size
    - `sizeof(VARIABLE)` (in bytes)
    - 1 byte = 8 bits
- Integers
    - `char c = 'A';` (1 byte; [ASCII Code](https://www.ascii-code.com/))
    - `int i = 42;` (4 bytes)
    - `short s = 123;` (typically 2 bytes)
    - `long l = 123456L;` (4 or 8 bytes)
    - `long long ll = 1234567890LL;` (8 bytes)
- Unsigned integers
    - `unsigned TYPE;` (non-negative integers with extended range)
- Floating point numbers
    - `float pi = 3.14;` (4 bytes; single-precision)
    - `double pi = 3.14159;` (8 byes; double-precision)
    - `long double pi = 3.141592L;` (8, 12 or 16 bytes)
- Read-only variables
    - `const TYPE VARIABLE;`
- Static variables
    - `static TYPE VARIABLE;`
    - Persist until program ends
- Structures
    - `struct`
        ```c
        struct TAG
        {
            TYPE1 VARIABLE1;
            TYPE2 VARIABLE2;
        };
        ```
    - `typedef`
        ```c
        typedef struct TAG NAMED_STRUCT;
        ```
        or
        ```c
        typedef struct TAG 
        {
            TYPE1 VARIABLE1;
            TYPE2 VARIABLE2; 
        } NAMED_STRUCT;
        ```
    - Memory size
        - The memory size of `struct` is often larger than the sum of its elements.
    - Data access
        - Dot operator (direct instances)
            - `STRUCT_VARIABLE.VARIABLE;`
        - Arrow operator (pointers)
            - `STRUCT_POINTER->VARIABLE;`
- Format specifiers
    - `int`: `printf("%d", 42);`
    - `char`: `printf("%c", 'A');`
    - `char[]` (strings): `printf("%s", "strings");`
    - `float`: `printf("%f", 3.14);`
    - `double` (for `scanf`): `scanf("%lf", &d);`
    - `long double`: `printf("%LF", 3.141592L);`
    - Pointer (address): `printf("%p", &ptr);`

## Strings & special characters
- String literals vs. String variables
    - String literals
        - Declarations
            - `char *str = "Hello";`
            - `const char *str = "Hello";` (good practice)
        - Read-only
        - Immutable
    - String variables
        - Declarations
            - `char str[] = "Hello";` (stack)
            - `char *str = malloc(10);` (heap)
        - Mutable
- Escape sequences
    - `\'`, `\"`, `\\`: single/double quote, backslash
    - `\0`: null character (end of string)
    - `\n`: new line (Enter key)
    - `\t`: tab space
    - `\r`: carriage return (Windows line endings)
    - `\b`: backspace (Erasing characters)
    - `\f`: form feed (Page break)
    - `\v`: vertical tab (Vertical spacing)
    - `\a`: bell/beep sound (Alert user)

## Array
- Syntax
    - `TYPE ARRAY_NAME[SIZE];` (static)
- Features
    - Zero-indexed
    - Contiguous memory
    - Variable name represents address (pointer), but they are not the same
        - Array variable is not a modifiable `lvalue` (locator value).
    - Static (stack) vs. Dynamic (heap)
- 1D arrays
    - `int ary[5] = {1, 2, 3, 4, 5};`
    - `int ary[3] = {0};` (`{0, 0, 0}`)
    - `char *string = "Hello";` (`{'H', 'e', 'l', 'l', 'o', '\0'}`)
- 2D arrays
    ```c
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    matrix[0][2]; // 3
    ```
- Multidimensional arrays
    ```c
    int cube[x][y][z] = {{{...}, ...}, ...};
    cube[i][j][k]; // *(cube + i*y*z + j*z + k)
    ```
- Dynamic arrays
    - 1D arrays (using `malloc`)
        ```c
        #include <stdlib.h>

        int size;
        int *ary;
        
        size = 3;
        ary = (int *) malloc(sizeof(int) * size);
        if (!ary)
        {
            return (1);
        }
        ...
        free(ary); // Remember to free!
        ary = NULL;
        ```

## Data structures & algorithms
- Types of data structures
    - Linked list
        - Singly linked list
            ```c
            #include <stdlib.h>

            typedef struct _node
            {
                TYPE VARIABLE;
                struct _node *next;
            } node;

            int main()
            {
               node *head;
               head = (node *)malloc(sizeof(node));
               head->next = (node *)malloc(sizeof(node));
               head->next->next = NULL;
            }
            ```
        - Doubly linked list
        - Circular linked list
    - Stack (Last-In-First-Out, LIFO)
    - Queue (First-In-First-Out, FIFO)
    - Tree
        - Binary tree
        - Binary search tree
        - Self-balancing binary search tree
        - Adelson-Velsky-Landis tree
        - Red–black tree
    - Graph
- Algorithms
    - Insert
    - Delete
    - Search
        - Linear search
        - Binary search
    - Sort
        - Bubble sort
        - Quick sort
        - Selection sort
        - Insertion sort
    - Recursion

## Conditional statements
- If-else
    ```c
    if (CONDITION)
    {
        ...;
    }
    else if (CONDITION) 
    {
        ...;
    } 
    else 
    {
        ...;
    }
    ```
    - Ternary operator: `(CONDITION) ? IF_TRUE : IF_FALSE;`
- Switch
    ```c
    switch (EXPRESSION) 
    {
        case CONSTANT1: 
            ...; 
            break;
        case CONSTANT2:
            ...;
            break;
        default: 
            ...;
    }
    ```
    - Integers only for expression
- For
    ```c
    for (INITIALIZATION; CONDITION; INCRE-/DECRE-MENT)
    {
        ...;
    }
    ```
    - Increment: `i++;`, `++i`
    - Decrement: `i--`, `--i`
- While
    ```c
    while (CONDITION)
    {
        ...;
    }
    ```
- Do-while
    ```c
    do 
    {
        ...;
    } while (CONDITION);
    ```
- Control statements
    - `break;`
    - `continue;`
- Relational operators
    - `==`: equal to
    - `!=`: not equal to
    - `>`, `>=`: greater than (or equal to)
    - `<`, `<=`: less than (or equal to)
- Logical operators
    - `&&`: AND
    - `||`: OR
    - `!`: NOT

## Libraries
- `<unistd.h>`
    - `write(FILE_DESCRIPTOR, BUFFER, COUNT);`
        - File descriptor (0: stdin, 1: stdout, 2: stderr)
        - Buffer: Memory address
        - Count: Number of bytes
        - Returns the length of characters
- `<stdio.h>`
    - `printf("%FORMAT_SPECIFIER, ...", VALUE, ...);`
    - `scanf("%FORMAT_SPECIFIER", &POINTER);`
        - `scanf("%d", &d);`
        - `scanf("%s", strings);`
- `<time.h>`
    - `time(NULL);`
        - Returns the number of seconds (`long`) since January 1, 1970 at 00:00:00 UTC.
- `<stdlib.h>`
    - `srand((unsigned)time(NULL));`
        - Seed the random number generator
    - `rand();`
        - Returns `int` from 0 to 32,767
    - `system("COMMAND");`
    - `malloc(SIZE_OF_MEMORY);`
    - `free(VARIABLE);`
- `<math.h>`
    - `pow(a, b)` (returns $a^b$)
- `<string.h>`
    - `strlen(str);`
    - `strcmp(str1, str2);`, `strncmp(str1, str2, size_t);`
    - `strcpy(dest, src);`, `strncpy(dest, src, size_t);`
    - `strcat(dest, src);`, `strncat(dest, src, size_t);`
    - `strchr(str, c);`
    - `strstr(string, str);`

## Resources
- https://www.onlinegdb.com/
- https://pythontutor.com/index.html
- https://valgrind.org/

## References
- https://www.tiobe.com/tiobe-index/
- https://homepage.ntu.edu.tw/~jfanc/AdvC.html
- https://42wolfsburgberlin.notion.site/C-Mother-19d937251cae812a94b6c07937955c77
- https://man7.org/index.html
