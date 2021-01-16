#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // We only have space for 3 bytes so will get an error
  // Also not using free to free up the used memory later
  // char *s = malloc(3);
  char *s = malloc(4);
  s[0] = 'H';
  s[1] = 'I';
  s[2] = '!';
  s[3] = '\0';

  // At first glance this works but we can't see the bugs happening under the surface
  // This is where valgrind comes in! Run valgrind ./memory which is a check like debug50
  printf("%s\n", s);

  // Add free to fix error
  free(s);
}