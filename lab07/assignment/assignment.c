#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numwords(char* cptr, char c) {
    int inword = 0;
    int words = 0;
    while (*cptr)
    {
        if (*cptr != c && !inword)
        {
            inword = 1;
            words++;
        }
        else if (*cptr == c && inword)
        {
            inword = 0;
        }
        cptr++;
    }
    return words;   
}

char **split(char* cptr, char c) {
    char **strings = malloc(numwords(cptr, c) * sizeof(char*));
    char *cptr2 = cptr;
    char **strings2 = strings;
    int inword = 0;
    while (*cptr2)
    {
        if (*cptr2 != c && !inword)
        {
            inword = 1;
            cptr = cptr2;
        }
        else if (*cptr2 == c && inword)
        {
            inword = 0;
            int chars = cptr2-cptr;
            *strings2 = malloc(chars * sizeof(char));
            strncpy(*strings2, cptr, chars);
            strings2++;
        }
        cptr2++;
    }
    if (*cptr2 == '\0' && inword)
    {
        int chars = cptr2-cptr;
        *strings2 = malloc(chars * sizeof(char));
        strncpy(*strings2, cptr, chars);
    }
    return strings;
}

int main() {
    char *string = " aa b a  c  d e";
    int n = numwords(string, ' ');
    char** strs = split(string, ' ');
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", strs[i]);
    }

    
    string = "\nline123\nline\nline\n\nllll\nsssssss";
    n = numwords(string, '\n');
    strs = split(string, '\n');
    for (i = 0; i < n; i++)
    {
        printf("%d: %s\n", i, strs[i]);
    }
    
    return 0;
}