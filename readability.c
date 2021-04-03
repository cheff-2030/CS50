#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declare formulas that will be used to analyze the string
int count_letters(string a);
int count_words(string a);
int count_sentences(string a);
int coleman_liau(double letters, double words, double sentences);



int main(void)
{
    //Get string from user and create variables for letters, words, sentences, and grade
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = coleman_liau(letters, words, sentences);
    
    //Prints Grade
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", grade);
    }
}

//Counts the number of letters in the string, not including numbers or punctuation or spaces
int count_letters(string a)
{
    int counter = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (isalpha(a[i]) > 1)
        {
            counter++;
        }
    }
    return counter;
}

//Counts the number of words in the string, based on number of spaces
int count_words(string a)
{
    int counter = 1;
    for (int i = 0; i < strlen(a); i++)
    {
        if (isspace(a[i]) > 1)
        {
            counter++;
        }
    }
    return counter;
}

//Counts the number of sentences in the string, based on number of . ! and ?
int count_sentences(string a)
{
    int counter = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == 33)
        {
            counter++;
        }
        else if (a[i] == 46)
        {
            counter++;
        }
        else if (a[i] == 63)
        {
            counter++;
        }
    }
    return counter;
}

//Calculates the grade level required
int coleman_liau(double letters, double words, double sentences)
{
    double L = letters / words * 100;
    double S = sentences / words * 100;
    
    double index = 0.0588 * L - 0.296 * S - 15.8;
    
    //Round result and convert to int
    int rounded = round(index);
   
    return rounded;
}