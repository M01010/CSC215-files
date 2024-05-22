#include <stdlib.h>
#include <string.h>
#include "stringMethods.h"

int length(char *s) {
    char *p = s;
    while (*p != '\0')
    {
        p++;
    }
    return p-s;
}

int compare(char *s, char*s2) {
    while (*s == *s2) {
        if (*s == '\0') {
            return 0;
        }
            s++;
            s2++;
    }
    return *s - *s2;
}
void swap(char *s1, char*s2) {
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
char *toEnd(char *originalString) {
    char *s2 = originalString;
    while (*s2 != '\0')
    {
        s2++;
    }
    s2--;
    return s2;
}
void reverse(char *s) {
    char *strEnd = toEnd(s);
    int l = length(s);
    int i;
    for (i = 0; i < l / 2; s++, strEnd--, i++)
    {
        swap(s, strEnd);
    }
}


int isPalindrome(char *s){
    char *end = toEnd(s);
    while (&(*end) >= &(*s))
    {
        if (*end != *s)
        {
            return 0;
        }
        end--;
        s++;
    }
    return 1;
}


char *findchar(char c, char* cptr) {
    while (*cptr != '\0')
    {
        if (*cptr == c)
        {
            return cptr;
        }
        cptr++;
    }
    return 0;
}


char *findlastchar(char c, char* cptr) {
    char *endcptr = toEnd(cptr);
    while (endcptr >= cptr)
    {
        if (*endcptr == c)
        {
            return endcptr;
        }
        endcptr--;
    }
    return 0;
}


void removeallspaces(char* cptr){
    char* cptr1 = cptr;
    while (*cptr1 != '\0')
    {
        char *cptr2 = cptr1;
        while (*cptr2 != '\0')
            {
                if (*cptr2 == ' ' && *(cptr2 + 1) != '\0')
                {
                    swap(cptr2, cptr2+1);
                }
                cptr2++;
            }
        cptr1++;
    }
    char *last = findchar(' ', cptr);
    *last = '\0';
}


void to_upper(char* cptr) {
    while (*cptr)
    {
        if (*cptr >= 'a' && *cptr <= 'z')
        {
            *cptr -= 32;
        }
        cptr++;
    }
}


int numwords(char* cptr) {
    int inword = 0;
    int words = 0;
    while (*cptr)
    {
        if (*cptr != ' ' && !inword)
        {
            inword = 1;
            words++;
        }
        else if (*cptr == ' ' && inword)
        {
            inword = 0;
        }
        cptr++;
    }
    return words;   
}

int numlines(char* cptr) {
    int in_line = 0;
    int lines = 0;
    while (*cptr)
    {
        if (*cptr != '\n' && !in_line)
        {
            in_line = 1;
            lines++;
        }
        else if (*cptr == '\n' && in_line)
        {
            in_line = 0;
        }
        cptr++;
    }
    return lines;   
}


char **split(char* cptr) {
    int num = numwords(cptr);
    char **strings = malloc(num * sizeof(char*));
    char *cptr2 = cptr;
    char **strings2 = strings;
    int inword = 0;
    while (*cptr2)
    {
        if (*cptr2 != ' ' && !inword)
        {
            inword = 1;
            cptr = cptr2;
        }
        else if (*cptr2 == ' ' && inword)
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