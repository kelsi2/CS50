#include <cs50.h>
#include <stdio.h>
#include <string.h>

// This code is correct but it assumes the number will be in the same place in the other array, what happens if the arrays are in the wrong order?
// Better to store the data in a different type (see phonebook2.c)
int main(void)
{
  string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
  // Phone numbers are stored as strings because they're not just numbers
  string numbers[4] = {"617-555-0100",
                       "617-555-0101",
                       "617-555-0102",
                       "617-555-0103"};

  for (int i = 0; i < 4; i++)
  {
    if (strcmp(names[i], "EMMA") == 0)
    {
      // The phone number will be stored at the same location, albeit in a different array
      printf("%s\n", numbers[i]);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}