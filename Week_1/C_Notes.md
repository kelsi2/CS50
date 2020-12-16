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
