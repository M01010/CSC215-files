#include <stdio.h>
int factorial(int x)
{
    if (x <= 1)
    {
        return 1;
    }
    return x * factorial(x - 1);
}
int main()
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        printf("Facotrial(%d) = %d\n", i, factorial(i));
    }

    return 0;
}
