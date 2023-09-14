#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start = get_int("Start size: ");

    // Prompt for end size
    float end = get_int("End size: ");

    // Calculate number of years until we reach threshold
    int years = 0;
    float population = start;
    population = start + start/12;
    years = 1;
    while (end > population)
    {
        population = population + population/12;
        years = years + 1;
    }
    printf("Years: %i\n",years);
    // Print number of years
    return 0;
}
