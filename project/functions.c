#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "functions.h"

char two[] = {'A', 'B', 'C'};
char three[] = {'D', 'E', 'F'};
char four[] = {'G', 'H', 'I'};
char five[] = {'J', 'K', 'L'};
char six[] = {'M', 'N', 'O'};
char seven[] = {'P', 'R', 'S'};
char eight[] = {'T', 'U', 'V'};
char nine[] = {'W', 'X', 'Y'};

char word[MAX_LETTERS + 1];

void writeWord(const char *word, const char *filename)
{
    FILE *f = fopen(filename, "a");
    if (!f)
    {
        fprintf(stderr, "couldnt open file %s", filename);
        exit(0);
    }
    fprintf(f, "%s\n", word);
    fclose(f);
}
void writePossible(const char *numbers, int index)
{
    if (index == MAX_LETTERS)
    {
        word[index] = '\0';
        writeWord(word, combinations_fname);
        return;
    }
    char *selectedLetters;
    switch (numbers[index])
    {
    case '2':
        selectedLetters = two;
        break;
    case '3':
        selectedLetters = three;
        break;
    case '4':
        selectedLetters = four;
        break;
    case '5':
        selectedLetters = five;
        break;
    case '6':
        selectedLetters = six;
        break;
    case '7':
        selectedLetters = seven;
        break;
    case '8':
        selectedLetters = eight;
        break;
    case '9':
        selectedLetters = nine;
        break;
    }
    int i;
    for (i = 0; i < 3; i++)
    {
        word[index] = selectedLetters[i];
        writePossible(numbers, index + 1);
    }
}

int isCorrect(const char *numbers)
{
    int n = strlen(numbers);
    if (n != MAX_LETTERS)
    {
        fprintf(stderr, "length must be equal to %d\n", MAX_LETTERS);
        return 0;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (numbers[i] < '2' || numbers[i] > '9')
        {
            fprintf(stderr, "%c is not between 2 and 9\n", numbers[i]);
            return 0;
        }
    }
    return 1;
}
int equal(char *s1, char *s2)
{
    if (strlen(s1) != strlen(s2))
    {
        return 0;
    }
    while (*s1)
    {
        if (tolower(*s1) != tolower(*s2))
        {
            return 0;
        }
        s1++;
        s2++;
    }
    return 1;
}
double percent(int num) {
    return (num / pow(3, MAX_LETTERS))*100;
}
int writeCorrectWords()
{
    FILE *f_comb = fopen(combinations_fname, "r");
    if (!f_comb)
    {
        fprintf(stderr, "couldnt open file %s", combinations_fname);
        exit(0);
    }
    FILE *f_words = fopen(words_fname, "r");
    if (!f_comb)
    {
        fprintf(stderr, "couldnt open file %s", words_fname);
        exit(0);
    }
    FILE *f_correct = fopen(correct_words_fname, "w");
    if (!f_correct)
    {
        fprintf(stderr, "couldnt open file %s", correct_words_fname);
        exit(0);
    }
    int i = 0;
    int num = 0;
    char comb[100];
    char word[100];
    while (fgets(comb, 100, f_comb) != NULL)
    {
        printf("\r%.1f/100", percent(++i));
        while (fgets(word, 100, f_words) != NULL)
        {
            if (equal(comb, word))
            {
                fputs(word, f_correct);
                num += 1;
            }
        }
        fseek(f_words, 0, SEEK_SET);
    }
    printf("\n");
    fclose(f_correct);
    fclose(f_words);
    fclose(f_comb);
    return num;
}