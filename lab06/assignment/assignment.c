#include <stdio.h>
void sort(int *, int n);
int main()
{
    printf("Input the number of elements to store in the array: ");
    int num;
    scanf("%d", &num);

    int arr[num];

    printf("input %d number of elements in the array:\n", num);
    int i;
    for (i = 0; i < num; i++)
    {
        printf("element - %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    sort(arr, num);

    printf("\n");
    printf("The elements in the array after sorting :\n");
    for (i = 0; i < num; i++)
    {
        printf("element - %d : %d\n", i + 1, arr[i]);
    }

    return 0;
}
void sort(int *arr, int n)
{
    int *i;
    for (i = arr; i <= arr + n; i++)
    {
        int *j;
        for (j = arr; j <= arr + n; j++)
        {
            if (*i < *j)
            {
                int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}