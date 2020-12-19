//This problem can be run in the CS50 IDE https://ide.cs50.io/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get credit card number from user
    long creditNum = get_long("What is your credit card number?\n");
    printf("The number you entered is: %li\n", creditNum);

    // get length of card by dividing by 10 until no digits left
    int i = 0;
    long cc = creditNum;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }

    // length must be 13, 15, or 16, return invalid and set length of num to 0 to end while loop
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // sum of every other digit multiplied by 2 (starting with second-to-last digit)
    int sum1 = 0;
    // sum of digits not multiplied by 2
    int sum2 = 0;
    // copy card number for dividing by 10 (last digit must be 0 to be valid)
    long copyCc = creditNum;
    // add sum1 and sum2
    int total = 0;
    // last digit
    int last;
    // second last digit
    int last2;
    // two digits of product in sum1
    int d1;
    int d2;

    do
    {
        // remove last digit and add to sum1
        last = copyCc % 10;
        copyCc = copyCc / 10;
        sum1 = sum1 + last;

        // remove second last digit
        last2 = copyCc % 10;
        copyCc = copyCc / 10;

        // double second last digit and add digits to sum2
        last2 = last2 * 2;
        d1 = last2 % 10;
        d2 = last2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (copyCc > 0);

    total = sum1 + sum2;

    // check if total is a valid cc number
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // get starting digits to find brand of cc
    long start = creditNum;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // check MC start digits (51, 52, 53, 54, 55)
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    // check for Amex (34 or 37)
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    // check for Visa (4)
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    // otherwise invalid
    else
    {
        printf("INVALID\n");
    }
}