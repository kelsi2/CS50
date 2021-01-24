#include "helpers.h"
#include <math.h>

// Convert image to grayscale
// All rgb must be the same value
// Calc average of values and make that the new value for that pixel
// Convert from float to int
// Do this for each pixel in a row
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed >= 0 && sepiaRed <= 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                sepiaRed = 255;
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaBlue >= 0 && sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                sepiaBlue = 255;
                image[i][j].rgbtBlue = sepiaBlue;
            }

            if (sepiaGreen >= 0 && sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                sepiaGreen = 255;
                image[i][j].rgbtGreen = sepiaGreen;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporary array to retain original values for calculating averages
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;

            sum_red = sum_blue = sum_green = counter = 0;

            // For each pixel loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Pixel outside rows?
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Pixel outside columns?
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Add to sums
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;

                    // Average and blur
                    image[i][j].rgbtRed = round(sum_red / counter);
                    image[i][j].rgbtBlue = round(sum_blue / counter);
                    image[i][j].rgbtGreen = round(sum_green / counter);
                }
            }
        }
    }
    return;
}