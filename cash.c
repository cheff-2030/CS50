#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get amount of change due
    float change2 = -1;
    while (change2 < 0)
    {
        change2 = get_float("Change Due: ");
    }
    
    // Convert change due to cents
    int change = round(change2 * 100);
    
    // Initialize coin amounts
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    // Calculate number of quarters required
    for (; change >= 25; quarters++)
    {
        change = change - 25;
    }

    // Calculate number of dimes required
    for (; change >= 10; dimes++)
    {
        change = change - 10;
    }

    // Calculate number of nickels required
    for (; change >= 5; nickels++)
    {
        change = change - 5;
    }

    // Calculate number of pennies required
    for (; change >= 1; pennies++)
    {
        change = change - 1;
    }

    // Calculate and print total number or coins required
    int coins = quarters + dimes + nickels + pennies;

    printf("%i \n", coins);
}