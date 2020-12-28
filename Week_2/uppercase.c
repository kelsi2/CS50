#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  string s = get_string("Before: ");
  printf("After: ");

  for (int i = 0, n = strlen(s); i < n; i++)
  {
    // If char is lowercase
    // if (s[i] >= 'a' && s[i] <= 'z')
    // {
    //   // convert to uppercase using ASCII character codes
    //   printf("%c", s[i] - 32);
    // }
    // else
    // {
    //   // Print the character since it's already uppercase
    //   printf("%c", s[i]);
    // }

    // Use the ctype library for automatic conversion [this will automatically check if it is upper or lower case]
    printf("%c", toupper(s[i]));
  }
  print("\n");
}