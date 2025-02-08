#include <stdio.h>
#include <stdbool.h>
int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    int a[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bool biggest = true;
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if ((dx * dy != 0) || (i + dx >= row) || (i + dx < 0) || (j + dy >= col) || (j + dy < 0) || (dx == 0 && dy == 0))
                        continue;
                    if (a[i][j] <= a[i + dx][j + dy])
                        biggest = false;
                }
            }
            if (biggest == true)
                printf("%d\n", a[i][j]);
        }
    }
}