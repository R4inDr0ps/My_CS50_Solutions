#include <cs50.h>
#include <stdio.h>

// Initialize functions
void draw_pyramid(int height);
void draw_row(int bricks, int height);

/// This main function will ask the user for the height of the pyramid to be printed
/// before sending it over to corresponding method to calculate the size of the pyramid.
int main(void)
{
    int height;
    // User needs to provide an int value above 0 to create a pyramid.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Then the user input will be used to calculate the size of the pyramid.
    draw_pyramid(height);
}

/// Sets the height of the pyramid using the user input value before
/// creating the width of the pyramid.
void draw_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        // we +1 to the parameter when calling for the index position i.
        int bricks = i + 1;
        draw_row(bricks, height);
    }
}

/// Sets the width of the pyramid after the height has been determined.
/// Spaces will be incremented similar to the width of the pyramid but in reverse
/// to align the pyramid to the right.
void draw_row(int bricks, int height) // parameter i + 1
{
    // Create a variable that will store the number of empty strings.
    int space = height - bricks - 1;

    // Align the pyramid to the right by adding empty strings, (" " (height - 1) -> (0)).
    for (int j = 0; j <= space; j++)
    {
        printf(" ");
    }

    for (int i = 0; i < bricks; i++)
    {
        printf("#"); // the actual blocks of the pyramid.
    }
    printf("\n"); // Adds new line after each successful row.
}
