#include <stdio.h>
#include "stringMethods.h"
int main() {
    char arr[] = "hello";
    printf("length: %d \n", length(arr));
    printf("compare: %d \n", compare(arr, "hi"));

    reverse(arr);
    printf("reverse: %s \n", arr);
    reverse(arr);

    char arr2[] = "wow";
    printf("%s is palindrome: %d \n", arr2, isPalindrome(arr2));
    char arr3[] = "woww";
    printf("%s is palindrome: %d \n", arr3, isPalindrome(arr3));

    printf("index of %c in %s: %ld \n", 'l', arr, findchar('l', arr) - arr);

    printf("index of last %c in %s: %ld \n", 'w', arr2, findlastchar('w', arr2) - arr2);
    
    char string[] = " aaa bb c d   e f  ";
    removeallspaces(string);
    printf("%s\n", string);

    to_upper(string);
    printf("%s\n", string);

    char string2[] = " aa b a  c  d e";
    printf("(%s) has %d words\n", string2, numwords(string2));

    char string3[] = "\naa\na\na\n\na\n\na\na";
    printf("(%s) has %d lines\n", string3, numlines(string3));

    int n = numwords(string2);
    char** strs = split(string2);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", strs[i]);
    }
    
    return 0;
}