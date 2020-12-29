#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
  int height = get_int("Height: ");

  draw(height);
}

void draw(int h)
{
  // Do nothing once height is 0
  if (h == 0)
  {
    return;
  }
  // This will start at the bottom of the period given height, continually taking away 1 to build the next row
  // Recursive input needs to get smaller each time
  draw(h - 1);

  // This will draw the first row (e.g if height = 4, this will draw the line of four hashes)
  // The line above will draw everything else
  for (int i = 0; i < h; i++)
  {
    printf("#");
  }
  printf("\n");
}