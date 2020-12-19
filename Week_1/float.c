// This code is meant to be run in the cs50 sandbox: https://sandbox.cs50.io/

#include <cs50.h>
#include <stdio.h>

int main(void) {
  float price = get_float("What's the price?\n");

  // .2f will only show two decimal places
  printf("Your total is %.2f.\n", price * 1.0625);
}
