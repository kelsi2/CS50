#include <cs50.h>
#include <stdio.h>
// String functions
#include <string.h>

int main(void)
{
  string s = get_string("Input: ");
  printf("Output: ");

  // Loop over the string until it ends (s[i] == '\0')
  // for (int i = 0; s[i] != '\0'; i++)

  // Find the length of the string using a function
  // This is not good practice because we are asking for the length each time the loop is run which takes a lot of processing power
  // int n = strlen(s);
  // Variable can be declared within the loop itself
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    // Print each character in the string
    printf("%c", s[i]);
  }
  printf("\n");
}