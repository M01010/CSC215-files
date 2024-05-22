#include <stdio.h>
void rearrangeArray(int arr[], int size)
{
    int i;
    int oddCounter = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2)
        {
            int temp = arr[i];
            arr[i] = arr[oddCounter];
            arr[oddCounter] = temp;
            oddCounter++;
        }
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
    int arr[] = {6, 3, 8, 9, 5};
    printArray(arr, 5);
    rearrangeArray(arr, 5);
    printArray(arr, 5);
    return 0;
}
