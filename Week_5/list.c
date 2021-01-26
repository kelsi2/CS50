#include <stdio.h>

int main(void)
{
  // Make an array of size 3, this is not dynamic, we need to decide the size at the beginning
  // int list[3];

  // list[0] = 1;
  // list[1] = 2;
  // list[2] = 3;

  // for (int i = 0; i < 3; i++)
  // {
  //     printf("%i\n", list[i]);
  // }

  // Dynamically allocate the array, 3x the size of an int
  // This example copies the array from one location to another
  // This process gets very expensive very quickly
  int *list = malloc(3 * sizeof(int));

  // Exit the program, something is wrong (likely no more memory)
  if (list == NULL)
  {
    return 1;
  }

  // We can still use square brackets, malloc still basically creates an array
  // This statically allocates the array to a specific stack frame
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // We can do the same with pointer arithmetic but this quickly becomes hard to read
  // *list = 1;
  // *(list + 1) = 2;
  // *(list + 2) = 3;

  // Make more space to move the array since we need it to be longer
  // int *tmp = malloc(4 * sizeof(int));

  // Reallocate the original memory instead of creating new memory, this allows us to resize the original memory
  int *tmp = realloc(list, 4 * sizeof(int));

  if (tmp == NULL)
  {
    free(list);
    return 1;
  }

  // Reassign list to tmp
  // Don't need to do this step when using realloc, this is done for us, original values are moved for us to a new address with the right amount of space
  // for (int i = 0; i < 3; i++)
  // {
  //     tmp[i] = list[i];
  // }

  // Add new value
  tmp[3] = 4;

  list = tmp;

  for (int i = 0; i < 4; i++)
  {
    printf("%i\n", tmp[i]);
  }

  free(list);
}