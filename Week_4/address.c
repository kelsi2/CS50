#include <stdio.h>

int main(void)
{
  // This exists at a certain address in the computer's memory
  // Prefix variable with & to see what address the variable is stored in, use %p (pointer) instead of %i
  // Use * to look inside a particular memory address, use %i
  // Using both of these together basically cancels out
  int n = 50;
  // printf("%p\n", *&n);

  // Declaring a pointer variable to store the address of n, need to preface with *
  // Type of p is int *
  // Declaring this way tells the system we know we are declaring an address, this is what we mean to do not an error
  int *p = &n;
  // Change to printf("%i\n", *p) to print the value of n
  printf("%p\n", p);
}