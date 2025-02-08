#include <stdio.h>
#include <stdbool.h>

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int *row_num = &r;
    int *col_num = &c;
    int a[r][c];
    for (int row = 0; row < *row_num; row++)
        for (int col = 0; col < *col_num; col++)
            scanf("%d", &a[row][col]);
    int type, k;
    while (scanf("%d%d", &type, &k) != EOF)
    {
        if (type == 1)
        {
            for (int i = 0; i < *col_num; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    a[j][i] += a[2 * k - 1 - j][i];
                }
                for (int j = 0; j < *row_num - 2 * k; j++)
                {
                    a[k + j][i] = a[k + j + k][i];
                }
                for (int j = 0; j < k / 2; j++)
                {
                    int tmp = a[j][i];
                    a[j][i] = a[k - 1 - j][i];
                    a[k - 1 - j][i] = tmp;
                }
            }
            *row_num -= k;
        }
        else if (type == 2)
        {
            for (int i = 0; i < *row_num; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    a[i][*col_num - 2 * k + j] += a[i][*col_num - 1 - j];
                }
            }
            *col_num -= k;
        }
        else if (type == 3)
        {
            for (int i = 0; i < k; i++)
            {
                for (int j = i + 1; j < k; j++)
                {
                    a[j][*col_num - k + i] += a[0 + i][*col_num - k + j];
                    a[0 + i][*col_num - k + j] = 0;
                }
            }
        }
    }
    for (int row = 0; row < *row_num; row++)
    {
        for (int col = 0; col < *col_num - 1; col++)
            printf("%d ", a[row][col]);
        printf("%d\n", a[row][*col_num - 1]);
    }
}