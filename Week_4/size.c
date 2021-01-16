#include <stdio.h>

int main(void)
{
  int *x;
  int *y;

  // Allocate the size of an int in memory, this will always return the right size no matter what system you are using (usually 4 on modern systems)
  x = malloc(sizeof(int));

  // Go to the location of x and place 42 there
  *x = 42;
  // Attempt to place 13 at y but we haven't allocated any memory there! y has no assigned value
  // If we haven't personally placed something there we can assume it is a garbage value that looks like an address but is not a valid address
  // This will cause a segmentation fault (the computer knows the location doesn't belong to you), program will crash
  // Need to use malloc like above to store something in this location
  *y = 13;

  // This will tell y to store its value at the same address as x (same as using malloc, we are just borrowing x's address here)
  y = x;

  // This assigns y, which now works, BUT we are ALSO reassigning x to the SAME value because they are sharing the same address!!!
  *y = 13;
}