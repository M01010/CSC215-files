#include <stdio.h>

void write(char *f) /* problem 1 */
{
    FILE *fptr = fopen(f, "w");
    if (!fptr)
    {
        printf("Couldnt open file\n");
        return;
    }
    printf("write to text file, write @ to stop\n");
    char c;
    scanf("%c", &c);
    while (c != '@')
    {
        fprintf(fptr, "%c", c);
        scanf("%c", &c);
    }
    fclose(fptr);
}

void read(char *f) /* problem 2 */
{
    FILE *fptr = fopen(f, "r");
    if (!fptr)
    {
        printf("Couldnt open file\n");
        return;
    }
    char c = getc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fptr);
    }
    fclose(fptr);
}

void copy(char *f1, char *f2) /* problem 3 */
{
    FILE *f1ptr = fopen(f1, "r");
    if (!f1ptr)
    {
        printf("Couldnt open file1 \n");
        return;
    }
    FILE *f2ptr = fopen(f2, "w");
    if (!f2ptr)
    {
        fclose(f1ptr);
        printf("Couldnt open file2 \n");
        return;
    }
    char c = getc(f1ptr);
    while (c != EOF)
    {
        fprintf(f2ptr, "%c", c);
        c = getc(f1ptr);
    }
    fclose(f1ptr);
    fclose(f2ptr);
}

void split(char *f) /* bonus */
{
    FILE *fptr = fopen(f, "r");
    if (!fptr)
    {
        printf("Couldnt open file\n");
        return;
    }
    FILE *fptr_letter = fopen("linesStartedWithLetters.txt", "w");
    if (!fptr_letter)
    {
        printf("Couldnt open file\n");
        fclose(fptr);
        return;
    }
    FILE *fptr_number = fopen("linesStartedWithNumbers.txt", "w");
    if (!fptr_number)
    {
        fclose(fptr);
        fclose(fptr_letter);
        printf("Couldnt open file\n");
        return;
    }
    FILE *fptr_other = fopen("otherLines.txt", "w");
    if (!fptr_other)
    {
        fclose(fptr);
        fclose(fptr_letter);
        fclose(fptr_number);
        printf("Couldnt open file\n");
        return;
    }
    char str[100];
    while (fgets(str, sizeof(str), fptr))
    {
        if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
        {
            fputs(str, fptr_letter);
        }
        else if (str[0] >= '0' && str[0] <= '9')
        {
            fputs(str, fptr_number);
        }
        else
        {
            fputs(str, fptr_other);
        }
    }
    fclose(fptr);
    fclose(fptr_letter);
    fclose(fptr_number);
    fclose(fptr_other);
}

int main()
{
    printf("write to file\n");
    write("file.txt");
    printf("reading from file\n");
    read("file.txt");
    printf("copying file\n");
    copy("file.txt", "file2.txt");
    printf("splitting lines\n");
    split("file.txt");
    return 0;
}