# Week 1 - C

```c
int main(void) {

}
```
  * Basic starting block in C

```c
printf( "hello, world\n" );
```
  * Like console.log (include f for formatted text)
  * Must use double quotes and semicolons
  * Newline is required to move the prompt down!

```c
#include <stdio.h>
```
  * Tell the computer where the function is saved/implemented (standard io.h)
  * Needs to be at the top of the code file

* Use CS50 sandbox to write C code, includes a terminal

* Input source code, Output machine code (binary)
  * Converted by compiler
  1. In terminal write clang (c language) -> This is our compiler, similar to Node
    * This will create a new file with machine code (a.out -> assembly output)
      * Can run clang -o <output filename> <input filename> to name the compiled file something other than a.out
      * When running ls compiled files have an asterisk after the name because they are executable
    * Same way TS files run
    * Need to run compiler each time a change is made
  2. Write ./a.out to run the program (in the current directory)

* get_string to ask for user input 
```c
get_string("What's your name?\n");
```
