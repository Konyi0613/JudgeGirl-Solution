#include <stdio.h>
#include <stdlib.h>
// #define DEBUG
int lake(int N, int M, int picture[N][M], int now_row, int now_col)
{
    int drow[4] = {-1, 1, 0, 0};
    int dcol[4] = {0, 0, -1, 1};
    int accumulate = 1;
    picture[now_row][now_col] = 2;
    for (int i = 0; i < 4; i++)
    {
        int next_row = now_row + drow[i];
        int next_col = now_col + dcol[i];
        if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M)
        {
            if (picture[next_row][next_col] != 1)
                continue;
            accumulate += lake(N, M, picture, next_row, next_col);
        }
    }
    return accumulate;
}

int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int picture[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &picture[i][j]);
    int lakes[N * M / 2 + 1];
    int lake_count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (picture[i][j] == 1)
            {
                lakes[lake_count] = lake(N, M, picture, i, j);
#ifdef DEBUG
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                        printf("%d ", picture[i][j]);
                    printf("\n");
                }
                printf("\n");
#endif
                lake_count++;
            }
#ifdef DEBUG
    printf("%d\n", lake_count);
#endif
    qsort(lakes, lake_count, sizeof(int), cmp);
    for (int i = 0; i < lake_count; i++)
        printf("%d\n", lakes[i]);
}