#include <stdio.h>

int main(void)
{
  for (int i = 0; i < 10; i++)
  {
    // Add this extra line for debugging purposes, remove before submitting
    // printf("i is now%i: ", i);
    printf("#\n");
  }
}

// No problems with syntax but we are printing 11 instead of 10
// Need to use < instead of <=