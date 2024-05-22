#include <stdio.h>
int abs(int x)
{
    return x > 0 ? x : -x;
}
void printMatrix(int n, int m, int arr[][m])
{
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            printf("%-5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int queensafe(int n, int arr[n][n], int qi, int qj)
{
    int i;
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                if (arr[i][qj])
                {
                    return 0;
                }
                if (arr[qi][j])
                {
                    return 0;
                }
                if (abs(qi - i) == abs(qj - j))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int solve8queens(int n, int arr[n][n], int col)
{
    if (col == n)
    {
        return 1;
    }

    int i;
    for (i = 0; i < n; i++)
    {
        if (queensafe(n, arr, col, i))
        {
            arr[col][i] = 1;
            if (solve8queens(n, arr, col + 1))
            {
                return 1;
            }
            arr[col][i] = 0;
            continue;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int board[8][8] = {0};
    solve8queens(8, board, 0);
    printMatrix(8, 8, board);
    int board2[4][4] = {0};
    solve8queens(4, board2, 0);
    printMatrix(4, 4, board2);

    return 0;
}
