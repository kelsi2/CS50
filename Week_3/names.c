#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

  for (int i = 0; i < 4; i++)
  {
    // This will NOT work like it does with numbers...a string is actually an array with multiple characters!
    // You need to compare strings to eachother rather than a direct comparison
    // if (names[i] =="EMMA")
    if (strcmp(names[i], "EMMA") == 0)
    {
      // Be sure to return a value or the function will keep running!
      // Return 0 for successful outcome, 1 for unsuccessful
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}