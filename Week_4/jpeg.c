// Detects if a file is a JPEG

#include <stdint.h>
#include <stdio.h>

// Defining a byte data type
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  // Check usage, must include 2 arguments if the user entered something
  if (argc != 2)
  {
    return 1;
  }

  // Open file
  FILE *file = fopen(argv[1], "r");

  // If no file stop running
  if (!file)
  {
    return 1;
  }

  // Read first three bytes, these indicate the type of file (doc, csv, jpg, etc.)
  BYTE bytes[3];

  // Read from the file (from file read 3 bytes from the bytes array)
  fread(bytes, sizeof(BYTE), 3, file);

  // Check first three bytes for jpg code
  if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
  {
    // There is more to this algo than checking the first three bytes so can't be completely sure
    printf("Maybe\n");
  }
  else
  {
    printf("No\n");
  }

  // Close file
  fclose(file);
}