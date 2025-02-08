#include <stdio.h>

int main()
{
    int L, r, c;
    scanf("%d%d%d", &L, &r, &c);
    int grid[r][c];
    for (int i = r - 1; i >= 0; i--)
        for (int j = 0; j < c; j++)
            grid[i][j] = 0;
    for (int i = 1; i <= L; i++)
    {
        int n;
        scanf("%d", &n);
        int prev_r, prev_c, now_r, now_c;
        scanf("%d%d", &prev_c, &prev_r);
        if (prev_r < 0 || prev_r >= r || prev_c < 0 || prev_c >= c)
        {
            printf("ERROR %d 1\n", i);
            return 0;
        }
        for (int t = 2; t < n + 1; t++)
        {
            scanf("%d%d", &now_c, &now_r);
            if (now_r < 0 || now_r >= r || now_c < 0 || now_c >= c)
            {
                printf("ERROR %d %d", i, t);
                return 0;
            }
            if (now_r == prev_r)
            {
                int big, small;
                if (now_c > prev_c)
                {
                    big = now_c;
                    small = prev_c;
                }
                else
                {
                    big = prev_c;
                    small = now_c;
                }
                for (int j = small; j <= big; j++)
                    grid[now_r][j] = 1;
            }
            else if (now_c == prev_c)
            {
                int big, small;
                if (now_r > prev_r)
                {
                    big = now_r;
                    small = prev_r;
                }
                else
                {
                    big = prev_r;
                    small = now_r;
                }
                for (int j = small; j <= big; j++)
                    grid[j][now_c] = 1;
            }
            else if (now_r - prev_r == now_c - prev_c)
            {
                int dr, dc, time;
                if (now_r > prev_r)
                {
                    dr = -1;
                    dc = -1;
                    time = now_r - prev_r + 1;
                }
                else
                {
                    dr = 1;
                    dc = 1;
                    time = prev_r - now_r + 1;
                }
                for (int j = 0; j < time; j++)
                    grid[now_r + dr * j][now_c + dc * j] = 1;
            }
            else if (now_r - prev_r == -now_c + prev_c)
            {
                int dr, dc, time;
                if (now_r > prev_r)
                {
                    dr = -1;
                    dc = 1;
                    time = now_r - prev_r + 1;
                }
                else
                {
                    dr = 1;
                    dc = -1;
                    time = prev_r - now_r + 1;
                }
                for (int j = 0; j < time; j++)
                    grid[now_r + dr * j][now_c + dc * j] = 1;
            }
            else
            {
                printf("ERROR %d %d\n", i, t);
                return 0;
            }
            prev_r = now_r;
            prev_c = now_c;
        }
    }
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
            printf("%d", grid[i][j]);
        printf("\n");
    }

}