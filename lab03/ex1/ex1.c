#include <stdio.h>
int main()
{
    int sum = 0;
    int count;
    scanf("%d", &count);
    int i;
    for (i = 0; i < count; i++)
    {
        int input;
        scanf("%d", &input);
        sum += input;
    }
    float avg = 0;
    if (count > 0)
    {
        avg = (float)sum / count;
    }
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}
