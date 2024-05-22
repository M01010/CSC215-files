#include <stdio.h>
#include "functions.h"
int main()
{
    char numbers[MAX_LETTERS + 1];
    do
    {
        printf("Write the numbers: ");
        scanf("%s", numbers);
    } while (!isCorrect(numbers));
    remove("combinations.txt");
    writePossible(numbers, 0);
    printf("Written all combinations of %s to text file\n", numbers);
    int i = writeCorrectWords();
    printf("Written all correct words (%d) to the file\n", i);
    return 0;
}