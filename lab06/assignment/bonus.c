#include <stdio.h>
void toUpper(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str -= 32;
        }
        str++;
    }
}
int main()
{

    char str[100] = {'\0'};

    char *p1 = str;

    printf("Enter your text: ");
    gets(str);
    toUpper(p1);
    printf("Uppercase String: %s\n", str);

    return 0;
}
