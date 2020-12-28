#include <cs50.h>
#include <stdio.h>

// Use this to allow for dynamic programs, the number of values in the array can be easily updated
// Const means value can't be changed elsewhere, same as JS (should always be capitalized)
// This is the only time we use global variables so we can change it before recompiling if needed
// const int N = 3;

// Declare function here so c knows it exists
float average(int length, int array[]);

int main(void)
{
  // This is not the best design. If we need to add further scores it gets very unmanageable
  // Also very repetitive code
  // int score1 = 72;
  // int score2 = 73;
  // int score3 = 33;

  // Store in an array instead
  // int scores[N];

  // Store values in the array by putting them at a particular index
  // scores[0] = 72;
  // scores[1] = 73;
  // scores[2] = 33;

  // This allows for dynamic code where we get the score from the user and create an array of that length using a loop
  int n = get_int("Number of scores: ");

  int scores[n];

  for (int i = 0; i < n; i++)
  {
    // User enters the scores starting at 1 instead of 0
    scores[i] = get_int("Score %i: ", i + 1);
  }

  // printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / N);
  // Use dynamic calculation defined below:
  // Use .1f to round to one decimal place
  printf("Average: %.1f\n", average(n, scores));
}

// Calculate average score dynamically rather than manually
// Need to explicitly state the length of the array in C, it doesn't remember it
float average(int length, int array[])
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  // Divide float instead of int to account for decimals
  return (float)sum / (float)length;
}