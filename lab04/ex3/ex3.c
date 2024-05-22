#include <stdio.h>

int search(int arr[], size_t size, int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0, 34, 6, 8, 9, 3, 5};
    printf("%d\n", search(arr, 7, 8));
    return 0;
}
