#include <stdio.h>

int main(void)
{
  // There are no values initialized in this array, so it should contain garbage values and it does:
  // -1748555312, 32767, 0 is what gets output because the computer hasn't just assigned these values for us
  // ALWAYS initialize values before using them!!!
  int scores[3];
  for (int i = 0; i < 3; i++)
  {
    printf("%i\n", scores[i]);
  }
}