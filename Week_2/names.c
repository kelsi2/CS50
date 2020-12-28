#include <stdio.h>

int main(void)
{
  string names[4];
  names[0] = "EMMA";
  names[1] = "RODRIGO";
  names[2] = "BRIAN";
  names[3] = "DAVID";

  // These print the same thing
  printf("%s\n", names[0]);
  // A string is an array of characters so we can print each by accessing the name at 0 then each character from 0-3
  // This is why we have a null character, the loop is running in the background when we print a string so we need to tell it the string is over
  printf("%c%c%c%c\n", names[0][0], names[0][1], names[0][2], names[0][3]);
}