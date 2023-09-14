#include <cs50.h>
#include <stdio.h>
#include <string.h>
//defining prototypes
int word_count(string entry);
int sentence_count(string entry);
int letter_count(string entry);

int main(void)
{
    //Taking string input
    string entry = get_string("Enter: ");
    float words = word_count(entry);
    float sentences = sentence_count(entry);
    float letters = letter_count(entry);
    //calculating letters per hundred words
    float L = (letters * 100) / words;
    //calculating sentences per hundred words
    float S = (sentences * 100) / words;
    //Plugging values into the formula
    float index = (588 * L - 2960 * S - 158000) / 10000;
    printf("index value :%f",index);
    int grade = index;
    float check = index - grade;
    //if condition for correct rounding off
    if(check>=0.5)
    {
        grade = grade + 1;
    }
    //if and else if for different outputs
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
int word_count(string entry)
{
    //getting length for upper limit of for loop
    int length = strlen(entry);
    //initiallizing count
    int count = 0;
    for (int i = 0; i < length ; i++)
    {
        //converting to ASCII
        int letter = entry[i];
        //setting ASCII condition of space
        if (letter == 32)
        {
            count = count + 1;
        }
    }
    count = count + 1;
    return count;
}
int letter_count(string entry)
{
    //getting length for upper limit of for loop
    int length = strlen(entry);
    //initiallizing count
    int count = 0;
    for (int i = 0; i < length ; i++)
    {
        //converting to ASCII
        int letter = entry[i];
        //setting ASCII condition of uppercase alphabets
        if (letter >= 65 && letter <= 90)
        {
            count = count + 1;
        }
        //setting ASCII condition of lower case alphabets
        else if (letter >= 97 && letter <= 122)
        {
            count = count + 1;
        }
    }
    return count;
}
int sentence_count(string entry)
{
    //getting length for upper limit of for loop
    int length = strlen(entry);
    //initiallizing count
    int count = 0;
    for (int i = 0; i < length ; i++)
    {
        //converting to ASCII
        int letter = entry[i];
        //setting ASCII condition for ! ? . to define sentences
        if (letter == 33 || letter == 63 || letter == 46)
        {
            count = count + 1;
        }
    }

    return count;
}