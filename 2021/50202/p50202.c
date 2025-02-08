#include <stdio.h>

int main()
{
    int h, w, k;
    scanf("%d%d%d", &h, &w, &k);
    int a[h][w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            scanf("%d", &a[i][j]);
    int max = 0;
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if (col >= k - 1 && col + k - 1 < w && row >= k - 1 && row + k - 1 < h)
            {
                int now_value = 0;
                for (int i = 0; i < k; i++)
                {
                    now_value += a[row - i][col - k + 1 + i];
                    now_value += a[row - k + 1 + i][col + i];
                    now_value += a[row + i][col + k - 1 - i];
                    now_value += a[row + k - 1 - i][col - i];
                }
                now_value -= (a[row][col - k + 1] + a[row - k + 1][col] + a[row][col + k - 1] + a[row + k - 1][col]);
                if (now_value > max)
                    max = now_value;
            }
        }
    }
    printf("%d", max);
}