#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Arrays can be initialized with static values like this rather than say numbers[0] = 4...etc.
  int numbers[6] = {4, 8, 15, 16, 23, 42};

  // Linear search algo:
  for (int i = 0; i < 6; i++)
  {
    if (numbers[i] == 50)
    {
      printf("Found\n");
    }
  }
  printf("Not found\n");
}