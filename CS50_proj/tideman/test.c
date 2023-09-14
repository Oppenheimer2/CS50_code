#include <stdio.h>
int main(void)
{
    int weight[] ={5,2,3,6,3};
    for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
                {
                    if(weight[j] < weight[j+1])
                    {
                        int a = weight[j];
                        int b = weight[j+1];
                        weight[j] = b;
                        weight[j+1] = a;
                    }
                }
        }
    for (int i = 0; i < 5; i++)
    {
        printf("%i",weight[i]);
    }
}