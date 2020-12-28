#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  // User needs to enter an argument, otherwise program will error out
  if (argc != 2)
  {
    printf("missing command-line argument\n");
    return 1;
  }
  // Otherwise print what the user has entered with no error
  printf("hello, %s\n", argv[1]);
  return 0;
}