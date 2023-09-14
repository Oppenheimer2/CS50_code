#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
    string input = get_string("ENTER: ");
    int length = strlen(input);
    int count = 0;
    for (int i =0 ;i < length ;i++ )
    {
        int letter = input[i];
        if(letter==33 || letter==63 || letter==46 )
        {
            count = count+1;
        }

    }

    printf("word count: %i\n",count);

}