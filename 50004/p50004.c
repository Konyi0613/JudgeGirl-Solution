#include <stdio.h>
#include <stdbool.h>

int main()
{
    int grid[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &grid[i][j]);
    int prev = 0, now;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    bool win = true;
    while (scanf("%d", &now) != EOF)
    {
        win = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (!(grid[i][j] == i * 4 + j + 1 || (i == 3 && j == 3 && grid[3][3] == 0)))
                {
                    win = false;
                    break;
                }
        if (win)
            break;
        if (now == 0)
            break;
        int now_r, now_c;
        bool found = false;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (grid[i][j] == now)
                {
                    found = true;
                    now_r = i;
                    now_c = j;
                    break;
                }
        if (!found)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int new_r = now_r + dr[i], new_c = now_c + dc[i];
            if (new_r >= 0 && new_r < 4 && new_c >= 0 && new_c < 4 && grid[new_r][new_c] == 0)
            {
                grid[new_r][new_c] = grid[now_r][now_c];
                grid[now_r][now_c] = 0;
                break;
            }
        }
        prev = now;
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", grid[i][0]);
        for (int j = 1; j < 4; j++)
            printf(" %d", grid[i][j]);
        printf("\n");
    }
    if (win)
        printf("1 %d\n", prev);
    else
        printf("0\n");
}