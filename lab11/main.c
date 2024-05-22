#include <stdio.h>
#include "stack.h"
void sort_stack(Stack *s)
{
    Stack *s2 = new_stack(10);
    while (!is_stack_empty(s))
    {
        int *x = (int *)pop(s);
        while (!is_stack_empty(s2) && *((int *)top(s2)) < *x)
        {
            push(s, pop(s2));
        }
        push(s2, x);
    }
    while (!is_stack_empty(s2))
    {
        push(s, pop(s2));
    }
}
int sum(Stack *s)
{
    int c = 0;
    Stack *s2 = new_stack(10);
    while (!is_stack_empty(s))
    {
        int *x = (int *)top(s);
        push(s2, pop(s));
        c += *x;
    }
    while (!is_stack_empty(s2))
    {
        push(s, pop(s2));
    }
    return c;
}
int combinations(Stack *s, int n)
{
    int sum_stack = sum(s);
    if (sum_stack == n)
    {
        print_stack(s);
        return 1;
    }
    if (sum_stack > n)
    {
        return 0;
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        push(s, &i);
        combinations(s, n);
        pop(s);
    }
    return 0;
}
int main()
{
    Stack *s = new_stack(10);
    int b = 2;
    push(s, &b);
    int a = 1;
    push(s, &a);
    int d = 4;
    push(s, &d);
    int c = 3;
    push(s, &c);
    print_stack(s);
    /*
    sorting a stack
    */
    printf("after sorting: \n");
    sort_stack(s);
    print_stack(s);
    /*
    sum of stack*/
    printf("%d\n", sum(s));
    /*
    combinations
    */
    int comb = 5;
    printf("stack combinations of %d\n", comb);
    Stack *s2 = new_stack(10);
    combinations(s2, comb);

    return 0;
}