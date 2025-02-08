#include <stdio.h>
#include <stdbool.h>

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int a[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            if (a[row][col] == 0)
                continue;
            if (col <= c - 3)
            {
                if (a[row][col] == a[row][col + 1] && a[row][col] == a[row][col + 2])
                {
                    a[row][col] = a[row][col + 1] = a[row][col + 2] = 0;
                    continue;
                }
            }
            if (row <= r - 3)
            {
                if (a[row][col] == a[row + 1][col] && a[row][col] == a[row + 2][col])
                {
                    a[row][col] = a[row + 1][col] = a[row + 2][col] = 0;
                    continue;
                }
            }
            if (col <= c - 2 && row <= r - 2)
            {
                if (a[row][col] == a[row + 1][col] && a[row][col] == a[row][col + 1])
                {
                    a[row][col] = a[row + 1][col] = a[row][col + 1] = 0;
                    continue;
                }
            }
            if (col >= 1 && row <= r - 2)
            {
                if (a[row][col] == a[row + 1][col] && a[row][col] == a[row][col - 1])
                {
                    a[row][col] = a[row + 1][col] = a[row][col - 1] = 0;
                    continue;
                }
            }
            if (col <= r - 2 && row >= 1)
            {
                if (a[row][col] == a[row - 1][col] && a[row][col] == a[row][col + 1])
                {
                    a[row][col] = a[row - 1][col] = a[row][col + 1] = 0;
                    continue;
                }
            }
            if (col >= 1 && row >= 1)
            {
                if (a[row][col] == a[row - 1][col] && a[row][col] == a[row][col - 1])
                {
                    a[row][col] = a[row - 1][col] = a[row][col - 1] = 0;
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}