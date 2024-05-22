#include <stdio.h>
int main()
{
    int MAX_SIZE = 1000;
    char input[MAX_SIZE];
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        input[i] = 0;
    }

    printf("enter a sentence: ");
    scanf("%[^\n]", input);
    int a_vowel = 0, e_vowel = 0, i_vowel = 0, o_vowel = 0, u_vowel = 0;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (input[i] == 'a' || input[i] == 'A')
        {
            a_vowel += 1;
        }
        else if (input[i] == 'e' || input[i] == 'E')
        {
            e_vowel += 1;
        }
        else if (input[i] == 'i' || input[i] == 'I')
        {
            i_vowel += 1;
        }
        else if (input[i] == 'o' || input[i] == 'O')
        {
            o_vowel += 1;
        }
        else if (input[i] == 'u' || input[i] == 'U')
        {
            u_vowel += 1;
        }
    }

    printf("\nA/a:%-10dE/e:%-10dI/i:%-10dO/o:%-10dU/u:%-10d\n", a_vowel, e_vowel, i_vowel, o_vowel, u_vowel);
    return 0;
}
