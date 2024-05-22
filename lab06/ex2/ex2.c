#include <stdio.h>
int *findLarger(int *a, int *b)
{
    if (*a > *b)
    {
        return a;
    }
    return b;
}

int main()
{
    int a = 0;
    int b = 0;
    printf("Input the first number: ");
    scanf("%d", &a);

    printf("Input the second number: ");
    scanf("%d", &b);

    int *p1;
    int *p2;
    p1 = &a;
    p2 = &b;
    int *larger = findLarger(p1, p2);
    printf("The number %d is Larger\n", *larger);
    return 0;
}
