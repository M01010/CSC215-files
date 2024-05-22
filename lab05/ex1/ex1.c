#include <stdio.h>

void printArray(int n, int m, int arr[n][m])
{

    printf("%-10s ", "");
    int i;
    for (i = 0; i < m; i++)
    {
        printf("%-5s[%d]", "", i);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%-10s[%d]", "studentGrades", i);
        int j;
        for (j = 0; j < m; j++)
        {
            printf("%-5d ", arr[i][j]);
        }
        printf("\n");
    }
}

int minimum(int n, int m, int arr[n][m])
{
    int min = arr[0][0];
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int maximum(int n, int m, int arr[n][m])
{
    int max = arr[0][0];
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int sumArray(int n, int m, int arr[n][m])
{
    int sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int average(int n, int m, int arr[n][m])
{
    int sum = sumArray(n, m, arr);
    return sum / (n * m);
}

int main()
{
    /*
    int n = 3;
    int m = 4;
    */
    int studentGrades[3][4] = {
        {1, 2, 3, 4},
        {5, 6, -1, 8},
        {9, 10, 11, 12},
    };
    printArray(3, 4, studentGrades);
    printf("min: %d\n", minimum(3, 4, studentGrades));
    printf("max: %d\n", maximum(3, 4, studentGrades));
    printf("avg: %d\n", average(3, 4, studentGrades));
    return 0;
}
