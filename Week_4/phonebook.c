#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // FILE is a datatype. This is assigning a pointer to a file
  // 2 args: file name and mode
  // We use fopen (file open) on phonebook.csv in append mode [add more contents] (we can also open with read [look at contents] or write [change contents])
  FILE *file = fopen("phonebook.csv", "a");

  // If the file doesn't exist just exit
  if (file == NULL)
  {
    return 1;
  }

  char *name = get_string("Name: ");
  char *number = get_string("Number: ");

  // Print the given values to the file, must include file name (in this case file opened above) and the values to be printed
  fprintf(file, "%s,%s\n", name, number);

  // Close the file
  fclose(file);
}