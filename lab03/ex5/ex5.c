#include <stdio.h>
int main()
{
    int i;
    for (i = 1; i <= 7; i++)
    {
        int j;
        for (j = 1; j <= 7 - i; j++)
        {
            printf("%s", " ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }

    return 0;
}
