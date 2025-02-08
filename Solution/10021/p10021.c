#include <stdio.h>

int main()
{
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        int grid[N][M], way[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &grid[i][j]);
                way[i][j] = 0;
            }
        int time = (N > M) ? M : N;
        for (int i = 0; i < time; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < M; j++)
                    if (grid[0][j] != 1)
                        way[0][j] = 1;
                    else
                        break;
                for (int j = 0; j < N; j++)
                    if (grid[j][0] != 1)
                        way[j][0] = 1;
                    else
                        break;
            }
            else
            {
                for (int j = i; j < M; j++)
                    if (grid[i][j] != 1)
                        way[i][j] = (way[i - 1][j] + way[i][j - 1]) % 10000;
                for (int j = i; j < N; j++)
                    if (grid[j][i] != 1)
                        way[j][i] = (way[j - 1][i] + way[j][i - 1]) % 10000;
            }
        }
        printf("%d\n", way[N - 1][M - 1]);
    }
}