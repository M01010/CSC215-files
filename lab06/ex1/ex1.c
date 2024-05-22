#include <stdio.h>
int main()
{
    char arr[100] = {'\0'};
    printf("Enter any string: ");
    char *p = arr;
    scanf("%s", p);
    printf("The entered string is: %s\n", p);
    return 0;
}
