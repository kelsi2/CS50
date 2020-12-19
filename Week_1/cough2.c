// This code is meant to be run in the cs50 sandbox: https://sandbox.cs50.io/

#include <stdio.h>

//(void) means there are no params
void cough(void);

int main(void) {
  for (int i = 0; i < 3; i++) {
    cough();
  }
}

// This is how we write a function in C (more explanation of void later)
//NOTE: No hoisting in C. Functions must be declared above the place where it is used.
//We get around this by putting the name up above (almost like an async function) so C knows it exists
void cough(void) {
  printf("cough\n");
}