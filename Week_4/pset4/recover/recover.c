#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define block_size 512

// Defining a byte data type
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *input = fopen(argv[1], "r");

    // If file can't be opened stop
    if (!input)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    // Buffer
    unsigned char buffer[block_size];

    // file counter
    int counter = 0;
    FILE *output = NULL;

    // Check for jpeg
    int jpg_found = 0; //false to start

    // Read block, repeat for all files
    while (fread(&buffer, block_size, 1, input) == 1)
    {
        // Check first three bytes for jpg code
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                fclose(output);
            }
            else
            {
                jpg_found = 1;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", counter);
            output = fopen(filename, "w");
            counter++;
        }

        if (jpg_found == 1)
        {
            fwrite(&buffer, block_size, 1, output);
        }
    }

    // Close files
    if (output == NULL)
    {
        fclose(output);
    }

    if (input == NULL)
    {
        fclose(input);
    }
    return 0;
}