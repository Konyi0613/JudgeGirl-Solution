#include <stdio.h>
#include <stdbool.h>

void reset(bool used[6])
{
    for (int i = 0; i < 6; i++)
        used[i] = false;
}

int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    int grid[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &grid[i][j]);
    int count = 0;
    bool used[6] = {0};
    for (int i = 1; i < row - 1; i++)
        for (int j = 0; j < col - 3; j++)
        {
            reset(used);
            bool repeat = false;
            for (int k = 0; k < 4; k++)
                if (used[grid[i][j + k] - 1])
                    repeat = true;
                else
                    used[grid[i][j + k] - 1] = true;
            if (repeat || (grid[i][j] + grid[i][j + 2] != 7) || (grid[i][j + 1] + grid[i][j + 3] != 7))
                continue;
            for (int up = 0; up < 4; up++)
                for (int down = 0; down < 4; down++)
                {
                    if (used[grid[i - 1][j + up] - 1] || used[grid[i + 1][j + down] - 1] || grid[i - 1][j + up] + grid[i + 1][j + down] != 7)
                        continue;
                    count++;
                }
        }
    printf("%d\n", count);
}