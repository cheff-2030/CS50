#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: \n");
    }
    
    for (int up = 1; up <= height; up++)
    {
        for (int space = 1; space <= (height - up); space++)
        {
           printf(" ");
        }
        for (int left = 1; left <= up; left++)
        {
           printf("#");
        }
        printf("  ");
        for (int right = 1; right <= up; right++)
        {
            printf("#");
        }
        printf("\n");
    }
}