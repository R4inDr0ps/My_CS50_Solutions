#include <cs50.h>
#include <stdio.h>

// Initialize functions
void draw_pyramid(int height);
void draw_row(int num_bricks);

// Modify to set max and min size of the pyramid
const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 50;

/// This main function will ask the user for the height of the pyramid to be printed
/// before sending it over to corresponding method to calculate the size of the pyramid.
int main(void)
{
    int height;
    // User needs to provide an int value above 0 to create a pyramid.
    do
    {
        height = get_int("Please type the height of pyramid between 1 - 50: ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    // Then the user input will be used to calculate the size of the pyramid.
    draw_pyramid(height);

    return 0;
}

/// Creates the size of the pyramid based on the height value given by the user.
void draw_pyramid(int height)
{
    // The first for-loop is responsible for the height of the pyramid.
    for (int i = 0; i < height; i++)
    {
        int num_bricks = i + 1;              // Increment the amount of bricks of the pyramid
        int space = height - num_bricks - 1; // Increment the amount of spaces to align the left
                                             // side of the pyramid to lean to the right

        // Start by calculating the spaces
        for (int j = 0; j <= space; j++)
        {
            printf(" ");
        }

        // Then call the function to draw the left side of the pyramid.
        draw_row(num_bricks);

        // We want 2 '#' worth of space between each pyramid side.
        printf("  ");

        // Then we call the same function to draw the right side of the pyramid.
        draw_row(num_bricks);

        printf("  \n"); // Adds new line after each successful row.
    }
}

/// This method creates the blocks for the pyramid accordingly to the height given by the user.
void draw_row(int num_bricks) // parameter i + 1
{

    for (int i = 0; i < num_bricks; i++)
    {
        printf("#");
    }
}
