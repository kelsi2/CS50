// This code is meant to be run in the cs50 sandbox: https://sandbox.cs50.io/

// Logical operators

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree?\n");

    // Check whether agreed (or same as JS, && also same)
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
