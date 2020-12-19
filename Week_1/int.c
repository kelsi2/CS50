// This code is meant to be run in the cs50 sandbox: https://sandbox.cs50.io/

#include <cs50.h>
#include <stdio.h>

int main(void) {
  int age = get_int("What's your age?\n");
  // int days = age * 365;

  printf("You are at least %i days old.\n", age * 365);
}