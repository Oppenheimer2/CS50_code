#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 33;
    x[2] = 21;
    
    printf("%i",x[1]);
}