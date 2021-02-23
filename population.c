#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startsize;
    do
    {
        startsize = get_int("Start Size: \n");
    }
    while (startsize < 9);
    
    
    // TODO: Prompt for end size
    int endsize;
    do
    {
        endsize = get_int("End Size: \n");
    }
    while (endsize < startsize);
    
    
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    for (years = 0; startsize < endsize; years++)
    {
        startsize = startsize + (startsize / 3) - (startsize / 4);
    }
    
    
    // TODO: Print number of years
    printf("Years: %i\n", years);
}