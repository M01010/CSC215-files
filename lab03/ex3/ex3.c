#include <stdio.h>
int main()
{
    int num = 7;
    int i;
    int sum = 0;
    for (i = 1; i <= 100; i++)
    {
        sum += num * i;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
