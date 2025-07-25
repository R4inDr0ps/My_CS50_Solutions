#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Initialize functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// Takes a string of text and calculates the Coleman-Liau index to place a grade for the user based on the difficulty of the text.
int main(void)
{
    // Promt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = (letters / words) * 100.0;
    float S = (sentences / words) * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade levels
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Calculates the number of letters
int count_letters(string text)
{
    int count = 0;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {

        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Calculates the number of words
int count_words(string text)
{
    int count = 1;
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Calculates the number sentences
int count_sentences(string text)
{
    int count = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
