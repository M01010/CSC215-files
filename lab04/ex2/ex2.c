#include <stdio.h>
#include "IntArray.h"
int main()
{
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int i;
    int size = 0;
    int input = 0;
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("enter a number: ");
        scanf("%d", &input);
        if (input == 0)
        {
            break;
        }
        arr[i] = input;
        size++;
    }

    int ind_max = max(arr, size);
    int second_max = secondMax(arr, size);
    double avg = average(arr, size);
    printf("Max index: %d\n", ind_max);
    printf("Max Number: %d\n", arr[ind_max]);
    printf("second max index: %d\n", second_max);
    printf("second max Number: %d\n", arr[second_max]);
    printf("Average: %.2f\n", avg);
    return 0;
}
