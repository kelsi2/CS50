#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)

{
  char *s = get_string("s: ");
  // Copy whatever is in s
  char *t = s;

  // Capitalize first character of t...this doesn't work. s also gets capitalized
  // e.g. all we have only copied the address of s, not s itself
  // Therefore when we change t we are actually changing s, they are the same variable since they have the same address
  t[0] = toupper(t[0]);

  printf("s: %s\n", s);
  printf("t: %s\n", t);
}