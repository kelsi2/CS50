// Copies a file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  // Ensure proper usage (user must enter program name, source destination, and copy destination)
  if (argc != 3)
  {
    fprintf(stderr, "Usage: copy SOURCE DESTINATION\n");
    return 1;
  }

  // open input file (read mode)
  FILE *source = fopen(argv[1], "r");
  if (source == NULL)
  {
    printf("Could not open %s.\n", argv[1]);
    return 1;
  }

  // Open output file (write mode)
  FILE *destination = fopen(argv[2], "w");
  if (destination == NULL)
  {
    fclose(source);
    printf("Could not create %s.\n", argv[2]);
    return 1;
  }

  // Copy source to destination, one BYTE at a time
  BYTE buffer;
  while (fread(&buffer, sizeof(BYTE), 1, source))
  {
    fwrite(&buffer, sizeof(BYTE), 1, destination);
  }

  // Close files
  fclose(source);
  fclose(destination);
  return 0;
}