#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, k, m, d;
    scanf("%d%d%d%d", &n, &k, &m, &d);
    int grid[n][n], pattern[k][k];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
    int pattern_sum = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &pattern[i][j]);
            pattern_sum += pattern[i][j];
        }
    int match_r = -1, match_c = -1;
    for (int i = 0; i < n - k + 1; i++)
        for (int j = 0; j < n - k + 1; j++)
        {
            int mismatch = 0, sum = 0;
            bool valid = true;
            for (int r = 0; r < k; r++)
                for (int c = 0; c < k; c++)
                {
                    if (grid[i + r][j + c] != pattern[r][c])
                        mismatch++;
                    sum += grid[i + r][j + c];
                    if (mismatch > m)
                    {
                        valid = false;
                        break;
                    }
                }
            if (sum - pattern_sum > d || pattern_sum - sum > d)
                valid = false;
            if (valid)
            {
                match_r = i;
                match_c = j;
            }
        }
    printf("%d %d\n", match_r, match_c);
}