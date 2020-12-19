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
string answer = get_string("What's your name?\n");

printf("Hello, %s\n", answer);
```
  * Set variable to store the answer from the user, also need to set the type of data the variable will store
  * %s is a placeholder to denote that a variable will be put here of type string
    * Use comma variable name to tell C what variable to plug in there
    * Can add as many placeholders/variables as you want in order

Full program:
```c
#include <cs50.h>
#include <stdio.h>

int main(void) {
  string answer = get_string("What's your name?\n");
  printf("hello, %s\n", answer);
}
```
  * Need to include cs50 file so the computer knows what string is. This is not native to C
  * When running compile need to include -lcs50 (clang -o string string.c -lcs50) to ensure it combines the code from both files into one machine code file
    * Easier method is to say "make string" which automatically generates the command line arguments needed to run the program (only use the file name, not the .c)

```c
int counter = 0;
```
* Declare a variable with the type, in this case integer

```c
counter = counter + 1;
counter += 1;
counter++;
```
* Incrementing variable (same as JS)
  * Don't need to use type here because the variable has been declared previously with the type

```c
if (x < y) {
  printf("x is less than y\n");
} else if (x > y) {
  printf("x is not less than y\n");
} else if (x == y) {
  printf("x is equal to y\n");
}
```
* Condition (same as JS)
  * Only use semicolons after actions, not at the end of a block
  * No === in C, only = and ==
  * Can use else at the end same as JS

```c
while (true) {
  printf("hello, world\n");
}
```
* This is an infinite loop, will go forever

```c
int i = 0;

while (i < 50) {
  printf("hello, world\n");
  i++;
}
```

```c
for (int i = 0; i < 50; i++) {
  printf("hello, world\n");
}
```

Data types:
  * Bool (True/false)
  * Char (single character)
  * Double (More digits after the decimal point than float)
  * Float (Decimal numbers)
  * Int (integer of a specific size [up to 4 billion])
  * Long (Like bigint, more bits than int)
  * String (More than one character)

CS50 library provides following functions which prompt the user for input:
  * get_char
  * get_double
  * get_float
  * get_int
  * get_long
  * get_string
  Placeholders:
  * %c (char)
  * %f (float, double)
  * %i (int)
  * %li (long)
  * %s (string)

