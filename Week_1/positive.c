// This code is meant to be run in the cs50 sandbox: https://sandbox.cs50.io/

// Abstraction and scope

#include <cs50.h>
#include <stdio.h>

//Not included with cs50 library, need to create it
int get_positive_int(void);

int main(void)
{
    int i = get_positive_int();
    printf("%i\n", i);
}

// Prompt user for positive integer
//int === type of output, void === params passed in
int get_positive_int(void)
{
    int n;
    //Runs action before checking the condition
    do
    {
        n = get_int("Positive Integer: ");
    }
    while (n < 1);
    return n;
}