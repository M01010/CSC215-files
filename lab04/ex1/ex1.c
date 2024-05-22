#include <stdio.h>
#include <string.h>

int main()
{
    const int MAX = 50;
    char firstName[MAX];
    char lastName[MAX];
    printf("enter you first name: ");
    scanf("%s", firstName);
    printf("enter you last name: ");
    scanf("%s", lastName);
    char fullName[MAX * 2];
    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
    printf("%s\n", fullName);
    return 0;
}
