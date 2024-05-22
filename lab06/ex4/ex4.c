#include <stdio.h>
int compare(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 > *str2)
        {
            return 1;
        }
        else if (*str1 < *str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    if (*str1 != '\0')
    {
        return 1;
    }
    else if (*str2 != '\0')
    {
        return -1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{

    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    char *p1 = str1;
    char *p2 = str2;

    printf("Enter first string: ");
    gets(p1);

    printf("Enter second string: ");
    gets(p2);

    int a = compare(p1, p2);
    if (a == 0)
    {
        printf("first string is lexicograpphically equal to second");
    }
    else if (a > 0)
    {
        printf("first string is lexicograpphically bigger than second");
    }
    else
    {
        printf("first string is lexicograpphically smaller than second");
    }
    printf("\n");

    return 0;
}
