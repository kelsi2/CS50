#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_valid(string s);

int main(int argc, string argv[])
{
  // Check that the user has entered a number
  if (argc != 2 || !check_valid(argv[1]))
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  else
  {
    int key = atoi(argv[1]);

    if (key > 0)
    {
      // Get input from user
      string plaintext = get_string("plaintext: ");

      printf("ciphertext: ");
      for (int i = 0, n = strlen(plaintext); i < n; i++)
      {
        char c = plaintext[i];

        // Check if the character is a letter
        if (isalpha(c))
        {
          char modifier = 'A';
          // If character is lowercase change modifier to lowercase
          if (islower(c))
          {
            modifier = 'a';
          }

          // Print using cipher formula
          printf("%c", (c - modifier + key) % 26 + modifier);
        }
        // If character is not a letter print it as it is
        else
        {
          printf("%c", c);
        }
      }
      printf("\n");
    }
  }
}

// Check if the character is a digit
bool check_valid(string s)
{
  for (int i = 0, len = strlen(s); i < len; i++)
    if (!isdigit(s[i]))
    {
      return false;
    }
  return true;
}