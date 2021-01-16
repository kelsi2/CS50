#include <stdio.h>

int main(void)
{
    // char *s is the same as calling string but is the official data type in c
    // char * gives the address of a char, we are calling the variable s
    char *s = "HI!";
    // We can see where the string starts by using %p
    // Each of these show addresses one byte apart!
    // printf("%p\n", &s[0]);
    // printf("%p\n", &s[1]);
    // printf("%p\n", &s[2]);

    // This will go to the address of s (first character only)
    printf("%c\n", *s);
    // Prints second character
    printf("%c\n", *(s + 1));
    // Final character
    printf("%c\n", *(s + 2));
}