#include <cs50.h>
#include <stdio.h>

// The task is to print a greeting message to the user.
int main(void)
{
    string name = "";

    // stores user input into variable
    name = get_string("What's your name? ");

    // print formated string with user input
    printf("hello, %s\n", name);
}
