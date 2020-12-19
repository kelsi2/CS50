//This problem can be run in the CS50 IDE https://ide.cs50.io/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask the user for their name
    string answer = get_string("What's your name?\n");

    //Print the resulting string with the users name
    printf("hello, %s\n", answer);
}