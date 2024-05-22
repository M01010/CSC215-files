#include <stdio.h>
int numOfOdd(int arr[], int size)
{
    int i;
    int count = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2)
        {
            count++;
        }
    }
    return count;
}
int numOfEven(int arr[], int size)
{
    return size - numOfOdd(arr, size);
}
int main()
{
    int arr[] = {1, 3, 5, 7, 8};
    printf("odd: %d\n", numOfOdd(arr, 5));
    printf("even: %d\n", numOfEven(arr, 5));
    return 0;
}
