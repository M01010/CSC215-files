#include <stdio.h>
void reverse(int arr[], int size)
{
    int i;
    for (i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    reverse(arr, 5);
    printArray(arr, 5);
    return 0;
}
