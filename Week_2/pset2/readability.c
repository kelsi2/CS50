#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Declare functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
  // Get user input
  string text = get_string("Text: ");

  // Avg letters/100 words
  float L = (100 * (float)count_letters(text) / (float)count_words(text));
  // Avg sentences/100 words
  float S = (100 * (float)count_sentences(text) / (float)count_words(text));

  // Coleman-Liau formula
  float grade = 0.0588 * L - 0.296 * S - 15.8;

  // Print reading level of text
  if (grade < 16 && grade >= 0)
  {
    printf("Grade %i\n", (int)round(grade));
  }
  else if (grade > 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Before Grade 1\n");
  }
}

// Count the letters in the string
int count_letters(string text)
{
  int sumletters = 0;

  for (int i = 0; i < strlen(text); i++)
  {
    if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
    {
      sumletters++;
    }
  }
  return sumletters;
}

// Count words in string
int count_words(string text)
{
  // Start at 1 to count first word
  int sumwords = 1;

  for (int i = 0; i < strlen(text); i++)
  {
    if (text[i] == ' ')
    {
      sumwords++;
    }
  }
  return sumwords;
}

// Count sentences in text
int count_sentences(string text)
{
  int sumsentences = 0;

  for (int i = 0; i < strlen(text); i++)
  {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
      sumsentences++;
    }
  }
  return sumsentences;
}