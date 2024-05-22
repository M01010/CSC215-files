#include "arrayFunctions.h"
#include <stdio.h>
void printMatrix(int n, int m, int arr[][m])
{
    int i;
    printf("%-5s", " ");
    for (i = 0; i < m; i++)
    {
        char str[] = {'[', i % 10 + 48, ']', '\0'};
        printf("%-5s", str);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        char str[] = {'[', i % 10 + 48, ']', '\0'};
        printf("%-5s", str);
        int j;
        for (j = 0; j < m; j++)
        {
            printf("%-5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int minimum(int n, int m, int arr[][m])
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

int maximum(int n, int m, int arr[][m])
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

int sumArray(int n, int m, int arr[][m])
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

int average(int n, int m, int arr[][m])
{
    int sum = sumArray(n, m, arr);
    return sum / (n * m);
}

int multiplyRowColumn(int n, int row[], int column[])
{
    int sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        sum += row[i] * column[i];
    }
    return sum;
}

void multiplyMatrix(int n, int m, int arr1[n][m], int b, int arr2[m][b], int arr3[n][b])
{
    int i;
    for (i = 0; i < n; i++) /* row index */
    {
        int j;
        for (j = 0; j < m; j++) /* column index */
        {
            int columnarr2[m];
            int k;
            for (k = 0; k < m; k++)
            {
                columnarr2[k] = arr2[k][j];
            }
            arr3[i][j] = multiplyRowColumn(m, arr1[i], columnarr2);
        }
    }
}