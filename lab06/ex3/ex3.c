#include <stdio.h>
int main()
{
    char vowels[] = {'a', 'e', 'i', 'u', 'o'};
    char *vowelsptr = vowels;
    char str[100] = {'\0'};
    char *p = str;
    printf("Input a string: ");
    scanf("%s", p);
    int numVowels = 0;
    int i;
    for (i = 0; *(p + i) != '\0'; i++)
    {
        int j;
        for (j = 0; j < 5; j++)
        {
            if (*(p + i) == *(vowelsptr + j))
            {
                numVowels++;
                break;
            }
        }
    }
    printf("Number of vowels: %d\n", numVowels);
    printf("Number of constants: %d\n", i - numVowels);
    return 0;
}
