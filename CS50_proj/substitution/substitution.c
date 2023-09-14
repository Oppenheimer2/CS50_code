#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // checking if there are exactly 2 inputs
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    //checking input length to be 26
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    //checking inputs to be only alphabets
    for (int j = 0; j < 26; j++)
    {
        if (!((argv[1][j] >= 65 && argv[1][j] <= 90) || (argv[1][j] >= 97 && argv[1][j] <= 122)))
        {
            printf("Usage: ./substitution key");
            return 1;
        }
    }
    //checking for repeated inputs
    for (int k = 0; k < 26; k++)
    {
        char check = argv[1][k];
        for (int l = k + 1; l < 25 - k ; l++)
        {
            if (check == argv[1][l])
            {
                return 1;
            }
        }
    }

    //taking plain text input
    string plain = get_string("plaintext: ");
    //getting length
    int len = strlen(plain);
    //using for loop going through the array to replace it with its corresponding key
    for (int i = 0; i < len; i++)
    {
        //for capital letters
        if (plain[i] >= 65 && plain[i] <= 90)
        {
            int pos = plain[i] - 65;
            plain[i] = toupper(argv[1][pos]);
        }
        //for small case letters
        else if (plain[i] >= 97 && plain[i] <= 122)
        {
            int pos = plain[i] - 97;
            plain[i] = tolower(argv[1][pos]);
        }
    }
    //printing result
    printf("ciphertext: %s\n", plain);
    return 0;
}