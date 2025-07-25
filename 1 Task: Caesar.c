#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize function
string encrypt_text(string plaintext, int caesar_key);

// This program let's the user create a cypher text done by Caesar.
// It demands 2 arguments from the user. one Key value and a text.
int main(int argc, string argv[])
{
    // Check user arguments to assess possibility for a ceasar's key
    if (argc != 2)
    {
        printf("Usage: /caesar key\n");
        return 1;
    }

    // Checks if the length of the next argument is a digit
    int argv_length = strlen(argv[1]);
    for (int i = 0; i < argv_length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: /caesar key\n");
            return 1;
        }
    }

    // If all is okay, the program will:
    // 1) Convert key value
    int key = atoi(argv[1]);

    // 2) Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    // 3) Encrypt the plain text using the key
    string ciphertext = encrypt_text(plaintext, key);

    // 4) Print the encrypted text
    printf("Ciphertext: %s\n", ciphertext);

    // 5) Free allocated memory
    free(ciphertext);
    return 0;
}

string encrypt_text(string plaintext, int key)
{
    // Encipher text with key
    int text_length = strlen(plaintext); // Let's the program evaluate the entire plaintext
    char *encrypted_text = malloc(text_length + 1); // Allocates some memory to encrypt the text

    // Check that the text is not empty
    if (encrypted_text == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Cyphers each character in the text to the corresponding key position from argc[1]
    for (int i = 0; i < text_length; i++)
    {
        // Stores calculated char to be printed
        char character = plaintext[i];
        if (isupper(character))
        {
            encrypted_text[i] = ((character - 'A' + key) % 26) + 'A'; // Upper case char
        }
        else if (islower(character))
        {
            encrypted_text[i] = ((character - 'a' + key) % 26) + 'a'; // Lower case char
        }
        else
        {
            encrypted_text[i] = character; // Non-alphabetical
        }
    }

    // Ends the string
    encrypted_text[text_length] = '\0';
    return encrypted_text; // Returns the encrypted text.
}
