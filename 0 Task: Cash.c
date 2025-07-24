#include <cs50.h>
#include <stdio.h>

// Magic numbers, convert values based on input currency. currently set to cents
const int MIN_VAL = 0;
const int QUARTERS_VAL = 25;
const int DIMES_VAL = 10;
const int NICKELS_VAL = 5;
const int PENNIES_VAL = 1;

// Initialize function
int calculate_coins(int *cents, int coin_type);

int main(void)
{
    // Promt user for change owed (in cents).
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < MIN_VAL);

    // Calculate how many quarters you hould give customer.
    int quarters = calculate_coins(&cents, QUARTERS_VAL);

    // Calculate how many dimes you should give customer.
    int dimes = calculate_coins(&cents, DIMES_VAL);

    // Calculate how many nickels you should give customer.
    int nickels = calculate_coins(&cents, NICKELS_VAL);

    // Calculate how many pennies you should give customer.
    int pennies = calculate_coins(&cents, PENNIES_VAL);

    // Sum the number of quarters, dimes, nickels and pennies used.
    // Print that sum
    int total = quarters + dimes + nickels + pennies;
    printf("%i\n", total);
}

int calculate_coins(int *cents, int coin_type)
{
    int sum = 0;
    while (*cents >= coin_type)
    {
        sum++;
        *cents -= coin_type; // Subtract the value of the coin_type from remaining cents.
    }
    return sum;
}
