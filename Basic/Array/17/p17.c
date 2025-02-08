#include <stdio.h>

int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    int a[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
    int avg[col];
    for (int i = 0; i < col; i++)
        avg[i] = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            avg[j] += a[i][j];
    for (int i = 0; i < col; i++)
        printf("%d\n", avg[i] / row);
}