#include <stdio.h>

int main(void)
{
  // Char must use single quotes, string uses double quotes
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';

  // This is known as casting, we are converting one data type (char) to another (int)
  // We can remove the int and it will know to convert based on the %i
  // printf("%i %i %i\n", c1, c2, c3);
  printf("%i %i %i\n", (int)c1, (int)c2, (int)c3);
}