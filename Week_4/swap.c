#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
  int x = 1;
  int y = 2;

  printf("x is %i, y is %i\n", x, y);
  // Pass in the address, not the actual values of x and y
  swap(&x, &y);
  printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
  // // Store a in a temporary location
  // int tmp = a;
  // // Reassign a to the same value as b
  // a = b;
  // // Reassign b to the value of tmp (the original value of a)...this does not work! a and b get switched but main doesn't know this because of stack memory
  // // Values returned in swap become garbage values when it finishes running, they are not accessible to main
  // // x and y have been copied into swap so the original values in main don't actually get impacted
  // // To solve this we should use the address of x and y rather than the actual values of x and y (use pointers)
  // b = tmp;

  // Now we are using pointers to the address rather than the values themselves
  int tmp = *a;
  *a = *b;
  *b = tmp;
}