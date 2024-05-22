#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int isPreposition(const char *word)
{
    char *preps[11] = {"in", "on", "under", "with", "at", "for", "of", "by", "to", "the", "from"};
    int n = 11;
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(word, preps[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
void capitalizeFirstLetterOfWordsExceptPrepositions(const char *file_name)
{
    FILE *fptr = fopen(file_name, "r+");
    if (!fptr)
    {
        printf("Error opening the file.\n");
        exit(0);
    }
    char readingstr[32];
    while (fscanf(fptr, "%s", &readingstr) != EOF)
    {
        if (readingstr[0] >= 'a' && readingstr[0] <= 'z' && !isPreposition(readingstr))
        {
            fseek(fptr, -strlen(readingstr), SEEK_CUR);
            char c = fgetc(fptr);
            fseek(fptr, -sizeof(char), SEEK_CUR);
            c = c - ('a' - 'A');
            fputc(c, fptr);
            fseek(fptr, strlen(readingstr) - sizeof(char), SEEK_CUR);
        }
    }
    fclose(fptr);
}
int main()
{
    char file_name[] = "input.txt";
    capitalizeFirstLetterOfWordsExceptPrepositions(file_name);
    printf("Text has been modified successfully!.\n");
    return 0;
}