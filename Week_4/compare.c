#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // This program works fine when working with integers
  // int i = get_int("i: ");
  // int j = get_int("j: ");

  // if (i == j)
  // {
  //   printf("Same\n");
  // }
  // else
  // {
  //   printf("Different\n");
  // }

  // When running this on strings however they are always different
  // This is because we are comparing the addresses, not the strings themselves
  // What is stored in s is the address, not the char/string itself
  // The computer just takes a reference point and retrieves what is stored there
  char *s = get_string("s: ");
  char *t = get_string("t: ");

  // if (s == t)

  // This will actually work, need to make sure it equals 0 for equality
  if (strcmp(s, t) == 0)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }

  printf("%p\n", s);
  printf("%p\n", t);
}