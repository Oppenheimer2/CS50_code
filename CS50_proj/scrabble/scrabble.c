#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //  Print the winner
    if(score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1<score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    //finding length of input string to set upper limit of loop
    int length  = strlen(word);
    //initiallizing score to 0
    int score = 0;
    //going through each position in string
    for(int i=0; i<length; i++)
    {
        //getting position in ASCII
        int position = toupper(word[i]);
        //convering so that alphabets are b/w 0 to 25
        position = position -65;
        //Condition so ! , , etc. are ignored
        if(position>=0 && position<=25)
        {
            score = score + POINTS[position];
        }
    }
    return score;
}

