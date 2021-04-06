#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_int(string argument);

int main(int argc, string argv[])
{
    //Check if user entered the correct number of command line arguments
    if (argc != 2)
    {
        printf("Error! Please enter a single command line argument.\n");
        return 1;
    }
    
    
    //Check if user entered a non-negative integer
    else if (check_int(argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //If argument is valid, then:
    else
    {
        //Convert string key to int
        int key = atoi(argv[1]);
    
    
        //Ask user for plaintext
        string plaintext = get_string("plaintext: ");
        
        
        //Find length of plaintext
        int char_count = strlen(plaintext);
       
       
        //Cipher based on input argument and print. Ensures that only upper and lowercase letters will be changed, and if a letter is changed to a non-alphabetical character it will loop back to an alphabetical character
        printf("ciphertext: ");
    
        for (int i = 0; i < char_count; i++)
        {
            if (isupper(plaintext[i]) != 0)
            {
                if (plaintext[i] + (key % 26) > 90)
                {
                    printf("%c", plaintext[i] + (key % 26) - 26);
                }
                else 
                {
                    printf("%c", plaintext[i] + (key % 26));
                }
            }
            else if (islower(plaintext[i]) != 0)
            {
                if (plaintext[i] + (key % 26) > 122)
                {
                    printf("%c", plaintext[i] + (key % 26) - 26);
                }
                else 
                {
                    printf("%c", plaintext[i] + (key % 26));
                }
            }
            else 
            {
                printf("%c", plaintext[i]);
            }
        }
        
        printf("\n");
        
        
        //Return No Error
        return 0;
    }
}



//Check whether the argument is made up of all integers
int check_int(string argument)
{
    int length = strlen(argument);
    int check = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (isdigit(argument[i]) != 0)
        {
            check++;
        }
    }
    
    if (check == length)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
