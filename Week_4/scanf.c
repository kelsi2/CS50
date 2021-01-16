#include <stdio.h>

int main(void)
{
  // int x;
  // printf("x: ");
  // // scanf is doing the same thing as the get functions from cs50 library (get_int, get_string, etc.) but without the built in protections of cs50 library
  // // This collects an integer from the user and assigns it to the address of x
  // // One of these protections is that in this case if the user enters something other than an integer it will just return 0 instead of prompting again
  // scanf("%i", &x);
  // printf("x: %i\n", x);

  // This will not compile when using strings because s is declared but not initialized, it's a garbage value (null), if we don't store anything there it doesn't get initialized
  // Need to run malloc or give it an amount of bytes to allocate using square brackets. This works but we don't know how many characters the user will enter (this was one of the protections of cs50 library, it would adjust memory needed depending on what the user entered)
  // char *s;
  char s[4];
  printf("s: ");
  // Don't need to use & here because s is an address already (this is the nature of strings and why we invoke them as char *)
  scanf("%s", s);
  printf("s: %s\n", s);
}