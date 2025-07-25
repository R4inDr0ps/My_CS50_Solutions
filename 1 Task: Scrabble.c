#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// List of points per letter (a-z || A-Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Initialize function
int calculate_score(string answer);

// The program will ask two players to write a word each, the program will then calculate the score between each word and tell who the winner is.
int main(void)
{
    int player_one_score = 0;
    int player_two_score = 0;

    // Promt the players for a word each
    string answer_one = get_string("Player 1: ");
    string answer_two = get_string("Player 2: ");

    // Calculate the scores
    player_one_score = calculate_score(answer_one);
    player_two_score = calculate_score(answer_two);

    // Announce the winner
    if (player_one_score > player_two_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_one_score < player_two_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_score(string answer)
{
    // Declare a new score
    int player_score = 0;

    // Iterate between the total length of the list as the size of the loop.
    for (int i = 0, len = strlen(answer); i < len; i++)
    {
        // Check that the next index is a letter.
        if (isalpha(answer[i]))
        {
            // Computes using the ASCII principle to determine
            // the position of each letter to the score on the list of points.
            if (isupper(answer[i]))
            {
                player_score +=
                    POINTS[answer[i] - 'A']; // Calculates each upper case letter to the list
            }
            else if (islower(answer[i]))
            {
                player_score +=
                    POINTS[answer[i] - 'a']; // Calculates each lower case leter to the list
            }
        }
    }
    return player_score; // Returns calculated score
}
