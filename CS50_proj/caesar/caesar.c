#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int length = strlen(argv[1]);
    for(int j = 0; j < length; j++)
    {
        if(!isdigit(argv[1][j]))
        {
        printf("Usage: ./caesar key");
        return 1;
        }
    }

    if(argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string plain = get_string("plaintext: ");
        int len = strlen(plain);
        printf("ciphertext: ");
        for(int i =0; i < len; i++)
        {
            if(plain[i] >= 65 && plain[i] <= 90)
            {
                printf("%c",(plain[i] + key - 65)%26 + 65);

            }
            else if(plain[i] >= 97 && plain[i] <= 122)
            {
                printf("%c",(plain[i] + key - 97)%26 + 97);

            }
            else
            {
                printf("%c",plain[i]);
            }
        }
        printf("\n");

    }
}
