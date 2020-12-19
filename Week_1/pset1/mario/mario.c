//This problem can be run in the CS50 IDE https://ide.cs50.io/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declare height globally
    int height;

    //Declare functions so they are accessible
    void print_spaces(int num);
    void print_hashes(int num);

    do
    {
        //Prompt user to enter the height of the pyramid until they enter value greater than 0
        height = get_int("How tall is the pyramid? (Enter a number between 1 and 8)\n");
    }
    while (height < 1 || height > 8);

    //Print one space between each hash
    int spaces = height - 1;
    //Print one hash
    int hashes = 1;

    //Print pyramid based on height
    for (int i = 0; i < height; i++)
    {
        print_spaces(spaces);
        print_hashes(hashes);
        printf("  ");
        print_hashes(hashes);
        printf("\n");
        spaces--;
        hashes++;
    }
}

//Helper funtion to print spaces
void print_spaces(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf(" ");
    }
}

//Helper function to print hashes
void print_hashes(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("#");
    }
}
