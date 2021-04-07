#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char UPPER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char LOWER[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int check_alpha(string input);
int check_duplicate(string input);

int main(int argc, string argv[])
{
    //Check if one key is entered
    if (argc != 2)
    {
        printf("Error! Only enter 1 key! \n");
        return 1;
    }
    
    //Check if key has 26 characters
    else if (strlen(argv[1]) != 26)
    {
        printf("Error! Only enter 26 characters per key!\n");
        return 1;
    }
    
    //Check if key only has alphabetical letters
    else if (check_alpha(argv[1]) == 1)
    {
        printf("Error! Only enter alphabetical letters in the key!\n");
        return 1;
    }
    
    //Check if key has any duplicate letters
    else if (check_duplicate(argv[1]) == 1)
    {
        printf("Error! No duplicate letters in the key!\n");
        return 1;
    }
    
    //No error; continue
    else
    {
        //Ask user for plaintext
        string plaintext = get_string("plaintext: ");
        
        //Find length of plaintext
        int char_count = strlen(plaintext);
       
        //Cipher based on input argument and print.
        printf("ciphertext: ");
    
        for (int i = 0; i < char_count; i++)
        {
            if (isalpha(plaintext[i]) == 0)
            {
                printf("%c", plaintext[i]);
            }
            
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plaintext[i] == UPPER[j])
                    {
                        if (isupper(argv[1][j]) != 0)
                            {
                                printf("%c", argv[1][j]);
                            }
                        else    
                            {
                                printf("%c", argv[1][j] - 32);
                            }
                    }
                    else if (plaintext[i] == LOWER[j])
                    {
                        if (islower(argv[1][j]) != 0)
                            {
                                printf("%c", argv[1][j]);
                            }
                        else 
                            {
                                printf("%c", argv[1][j] + 32);
                            }
                    }
                }
            }
        }
        printf("\n");
        
        //Return No Error
        return 0; 
    }
}



//Check whether every character in an entered string is alphabetical
int check_alpha(string input)
{
    int counter = 0;
    
    for (int x = 0; x < 26; x++)
        {
            if (isalpha(input[x]) != 0)
            {
                counter++;
            }
        }
    
    if (counter != 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//Check whether any letters are duplicated in an entered string
int check_duplicate(string input)
{
    int counter2 = 0;
    
    for (int y = 0; y < 26; y++)
        {
            for (int z = 0; z < 26; z++)
            {
                if (input[y] == input [z])
                {
                    counter2++;
                }
            }
        }
    
    if (counter2 != 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}