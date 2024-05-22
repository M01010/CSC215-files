#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void shiftFile(FILE *f, int n) {
    fseek(f, n, SEEK_CUR);
    char c = fgetc(f);
    if (c == EOF)
    {
        return;
    }
    fseek(f, - (n + 1), SEEK_CUR);
    fputc(c, f);
    shiftFile(f, n);
}
void replace(char *findstr, char *replacestr)
{

    FILE *fptr = fopen("file1.txt", "r+");

    if (!fptr)
    {
        printf("Error opening the file.\n");
        exit(0);
    }

    char readingstr[strlen(findstr)];
    while (fscanf(fptr, "%s", &readingstr) != EOF)
    {
        if (strcmp(findstr, readingstr) == 0)
        {
            int f = strlen(findstr);
            int r = strlen(replacestr);
            if (f == r)
            {
                fseek(fptr, -strlen(readingstr), SEEK_CUR);
                fprintf(fptr, "%s", replacestr);
            }
            else if (f > r) {
                fseek(fptr, -strlen(readingstr), SEEK_CUR);
                fprintf(fptr, "%s", replacestr);
                int diff = f - r;
                shiftFile(fptr, diff);
            }
            else {

            }
        }
    }
    fclose(fptr);
}

int main()
{

    printf("Enter the word you want to find: \n");
    char c1[20];
    scanf("%s", c1);
    printf("Enter the word you want to replace (with same length first word): \n");
    char c2[20];
    scanf("%s", c2);
    replace(c1, c2);
    return 0;
}