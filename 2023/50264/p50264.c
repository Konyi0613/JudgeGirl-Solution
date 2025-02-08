#include <stdio.h>
#include <stdbool.h>
int main()
{
    int N, M, L, W; // N,L for row numbers, M,W for col numbers
    int x, y;       // for shadow's bottom left
    int s, k;       // s for step length, k for step number
    scanf("%d%d%d%d%d%d%d%d", &N, &M, &L, &W, &x, &y, &s, &k);
    int sun[N][M], tmp[N][M];
    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < M; j++)
            scanf("%d", &sun[i][j]);
    int time = k + 1;
    while (time--)
    {
        bool covered = false;
        if (x < M && (x + W) > 0 && y < N && (y + L) > 0)
            covered = true;
        else
        {
            x -= s;
            y -= s;
            continue;
        }
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = 0; j < M; j++)
            {
                if (i >= y && i <= y + L - 1 && j >= x && j <= x + W - 1)
                    tmp[i][j] = 0;
                else
                    tmp[i][j] = sun[i][j];
                if (covered)
                {
                    if (j == M - 1)
                        printf("%d\n", tmp[i][j]);
                    else
                        printf("%d ", tmp[i][j]);
                }
            }
        }
        if (covered)
            printf("\n");
        x -= s;
        y -= s;
    }
}