#include <stdio.h>
#include "arrayFunctions.h"
int main()
{
    int n = 2;
    int m = 3;
    int arr1[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    int a = 3;
    int b = 2;
    int arr2[3][2] = {
        {10, 11},
        {20, 21},
        {30, 31},
    };
    int resultMatrix[2][2] = {{0}};
    printMatrix(n, m, arr1);
    printMatrix(a, b, arr2);
    multiplyMatrix(n, m, arr1, b, arr2, resultMatrix); /* assuming m = a */
    printMatrix(n, b, resultMatrix);

    printf("\n\n");

    n = 2;
    m = 2;
    int arr3[2][2] = {
        {1, 2},
        {3, 4},
    };
    a = 2;
    b = 2;
    int arr4[2][2] = {
        {5, 6},
        {7, 8},
    };
    int resultMatrix2[2][2] = {{0}};
    printMatrix(n, m, arr3);
    printMatrix(a, b, arr4);
    multiplyMatrix(n, m, arr3, b, arr4, resultMatrix2); /* assuming m = a */
    printMatrix(n, b, resultMatrix2);
    return 0;
}
