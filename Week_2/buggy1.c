#include <stdio.h>

int main(void)
{
  string name = get_string("What's your name?\n");
  printf("hello, %s", name);
}

// error: Need to include cs50.h