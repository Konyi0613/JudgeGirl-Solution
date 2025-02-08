#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int grid[2][n][n], life_time[n][n];
    int max_r, max_c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[0][i][j]);
            life_time[i][j] = grid[0][i][j];
            if (grid[0][i][j] == 1)
            {
                max_r = i;
                max_c = j;
            }
        }
    int from = 0, to = 1, max_life_time = 1;
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, 1, -1, 0, -1, 1};
    for (int i = 0; i < k; i++)
    {
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
            {
                int neighbor = 0;
                for (int t = 0; t < 8; t++)
                {
                    int next_r = r + dr[t];
                    int next_c = c + dc[t];
                    if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && grid[from][next_r][next_c] == 1)
                        neighbor++;
                }
                if (grid[from][r][c] == 1)
                {
                    if (neighbor < 2 || neighbor > 3)
                    {
                        grid[to][r][c] = 0;
                        if (life_time[r][c] > max_life_time || (life_time[r][c] == max_life_time && (r > max_r || (r == max_r && c > max_c))))
                        {
                            max_life_time = life_time[r][c];
                            max_r = r;
                            max_c = c;
                        }
                        life_time[r][c] = 0;
                    }
                    else
                    {
                        grid[to][r][c] = 1;
                        life_time[r][c]++;
                    }
                }
                else
                {
                    if (neighbor == 3)
                    {
                        grid[to][r][c] = 1;
                        life_time[r][c] = 1;
                    }
                    else
                        grid[to][r][c] = 0;
                }
            }
        from = to;
        to = 1 - from;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (life_time[i][j] > max_life_time || (life_time[i][j] == max_life_time && (i > max_r || (i == max_r && j > max_c))))
            {
                max_life_time = life_time[i][j];
                max_r = i;
                max_c = j;
            }
    for (int i = 0; i < n; i++)
    {
        printf("%d", grid[from][i][0]);
        for (int j = 1; j < n; j++)
            printf(" %d", grid[from][i][j]);
        printf("\n");
    }
    printf("%d %d\n", max_r + 1, max_c + 1);
}