#include <stdio.h>
#include <ctype.h>
void encryptFile(const char *inputFile, const char *outputFile, int shift)
{
    FILE *f1 = fopen(inputFile, "r");
    if (!f1)
    {
        printf("Couldnt open input file");
        return;
    }
    FILE *f2 = fopen(outputFile, "w");
    if (!f2)
    {
        fclose(f1);
        printf("Couldnt open output file");
        return;
    }
    char c = fgetc(f1);
    while (c != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c += shift;
            if (c > 'z')
            {
                c = c % 26;
                c += 'a';
            }
        }
        fputc(c, f2);
        c = fgetc(f1);
    }
    fclose(f1);
    fclose(f2);
}
void decryptFile(const char *inputFile, int shift)
{
    FILE *f1 = fopen(inputFile, "r");
    if (!f1)
    {
        printf("Couldnt open file");
        return;
    }
    char c = fgetc(f1);
    while (c != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c -= shift;
            if (c < 'a')
            {
                c += 26;
            }
        }
        putchar(c);
        c = fgetc(f1);
    }
    fclose(f1);
}
int main()
{
    char inputFile[] = "input.txt";
    char encryptedFile[] = "encrypted.txt";
    int shift = 3;
    /* Shift value for Caesar cipher
    Encrypt the input file
    */
    encryptFile(inputFile, encryptedFile, shift);
    printf("File encrypted.\n");
    /* Decrypt the encrypted file and print it to the console */
    decryptFile(encryptedFile, shift);
    return 0;
}