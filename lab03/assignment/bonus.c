#include <stdio.h>

float piInfinite(int terms)
{
    int i;
    float sum = 0;
    for (i = 0; i < terms; i++)
    {
        float res = (float)4 / (1 + i * 2);
        if (i % 2)
        {
            res = -res;
        }
        sum += res;
    }
    return sum;
}
int main()
{
    int i;
    for (i = 1; i <= 50; i++)
    {
        printf("pi(%d) = %.4f\n", i, piInfinite(i));
    }
    return 0;
}
