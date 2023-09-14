#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            image[i][j].rgbtRed = average/3;
            image[i][j].rgbtBlue = average/3;
            image[i][j].rgbtGreen = average/3;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE TEMP = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = TEMP;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimg[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i + 1 < height && i - 1 > 0 && j + 1 < width && j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed)/9;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/9;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/9;
            }
            else if(i + 1 < height && i - 1 > 0 && j + 1 < width )
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed +  image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j+1].rgbtRed)/6;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +  image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen)/6;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue)/6;
            }
            else if(i + 1 < height && i - 1 > 0 && j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed +  image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed +  image[i-1][j-1].rgbtRed )/6;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen +  image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen +  image[i-1][j-1].rgbtGreen )/6;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue +  image[i-1][j-1].rgbtBlue )/6;
            }
            else if(i - 1 > 0 && j + 1 < width && j - 1 > 0)
            {
               tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed +  image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed)/6;
               tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/6;
               tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/6;
            }
            else if( i - 1 > 0 &&  j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed +  image[i][j-1].rgbtRed + image[i-1][j].rgbtRed +  image[i-1][j-1].rgbtRed )/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen +  image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen)/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue  + image[i-1][j-1].rgbtBlue )/4;
            }
            else if (i + 1 < height &&  j + 1 < width )
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed +  image[i+1][j].rgbtRed +  image[i+1][j+1].rgbtRed )/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +  image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue +  image[i+1][j+1].rgbtBlue )/4;
            }
            else if (i + 1 < height && j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed +  image[i][j-1].rgbtRed +  image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed )/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen +  image[i][j-1].rgbtGreen +  image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen )/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue )/4;
            }
            else if ( i - 1 > 0 && j + 1 < width)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen  + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue  + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/4;
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimg[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx ={
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}};
    int Gy = {{-1,-2,-1},{0,0,0},{1,2,1}};
    RGBTRIPLE tempimg[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i + 1 < height && i - 1 > 0 && j + 1 < width && j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed)/9;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/9;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/9;
            }
            else if(i + 1 < height && i - 1 > 0 && j + 1 < width )
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed +  image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j+1].rgbtRed)/6;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +  image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen)/6;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue)/6;
            }
            else if(i + 1 < height && i - 1 > 0 && j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed +  image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed +  image[i-1][j-1].rgbtRed )/6;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen +  image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen +  image[i-1][j-1].rgbtGreen )/6;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue +  image[i-1][j-1].rgbtBlue )/6;
            }
            else if(i - 1 > 0 && j + 1 < width && j - 1 > 0)
            {
               tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed +  image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed)/6;
               tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/6;
               tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/6;
            }
            else if( i - 1 > 0 &&  j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed +  image[i][j-1].rgbtRed + image[i-1][j].rgbtRed +  image[i-1][j-1].rgbtRed )/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen +  image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen)/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue  + image[i-1][j-1].rgbtBlue )/4;
            }
            else if (i + 1 < height &&  j + 1 < width )
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed +  image[i+1][j].rgbtRed +  image[i+1][j+1].rgbtRed )/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +  image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue +  image[i+1][j+1].rgbtBlue )/4;
            }
            else if (i + 1 < height && j - 1 > 0)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed +  image[i][j-1].rgbtRed +  image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed )/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen +  image[i][j-1].rgbtGreen +  image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen )/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue +  image[i][j-1].rgbtBlue +  image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue )/4;
            }
            else if ( i - 1 > 0 && j + 1 < width)
            {
                tempimg[i][j].rgbtRed = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/4;
                tempimg[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen  + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/4;
                tempimg[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue  + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/4;
            }
        }
    }

    return;
}
