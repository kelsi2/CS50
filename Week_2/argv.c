#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  // argc of 2 means 2 words have been entered in argv, print the second which is the user input
  // The file name is the first input so user input starts at 2!
  if (argc == 2)
  {
    printf("hello, %s\n", argv[1]);
  }
  else
  {
    printf("hello, world\n");
  }
}