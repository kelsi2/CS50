// This code is meant to be run in the cs50 sandbox: https://sandbox.cs50.io/

#include <cs50.h>
#include <stdio.h>

int main(void) {
  int n = get_int("n: ");

  //n divided by 2 has a remainder of 0 so is even
  if (n % 2 == 0) {
    printf("even\n");
  } else {
    printf("odd\n");
  }
}