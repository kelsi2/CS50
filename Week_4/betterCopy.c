#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)

{
  char *s = get_string("s: ");

  // Need to tell the computer to create a new space in memory for the copied string so it doesn't store at the same location
  // malloc == memory allocation, this gives t its own pointer
  // To do this dynamically take the length of s (the string we are copying) and add one for the null character
  char *t = malloc(strlen(s) + 1);

  // Can cause computer to hang if t doesn't exist and we try to keep going, this safeguards against memory errors
  // Null is the absence of an address, a value that doesn't exist in memory, only used in the context of pointers
  // This is different from nul or \0, used in the context of characters
  if (t == NULL)
  {
    return 1;
  }

  // Loop over all characters in s and copy them to t
  // Need to say <= n (rather than < n) to include the null character
  // for (int i = 0, n = strlen(s); i <= n; i++)
  // {
  //   // This can also be written as *(t + i) = *(s + i); Basically saying go to the location of t or s and add i offset
  //   // Square brackets are acceptable and more readable
  //   t[i] = s[i];
  // }

  // We can actually do this even more simply!
  // Two args: destination, source
  strcpy(t, s);

  // This works now to only capitalize t, s remains uncapitalized. We have made a true copy
  // Can also write as *t = toupper(*t); but again is less readable
  // Include error checking to be sure user has actually entered something to capitalize
  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);

  // If we use malloc we need to give the memory back to the computer because memory is finite, we need to put it back so we don't run out of memory
  // Pass in the address the memory is stored at, the computer knows how to free up the memory based on this variable
  free(t);
}