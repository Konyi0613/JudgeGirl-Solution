#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int a[N][N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                a[i][j][k] = i * N * N + j * N + k;
    for (int counter = 0; counter < M; counter++)
    {
        int type, layer;
        scanf("%d%d", &type, &layer);
        if (type == 0)
        {
            int clone[N][N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    clone[i][j] = a[layer][i][j];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    a[layer][j][N - 1 - i] = clone[i][j];
        }
        else if (type == 1)
        {
            int clone[N][N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    clone[i][j] = a[i][j][layer];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    a[N - 1 - j][i][layer] = clone[N - 1 - i][N - 1 - j];
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
                printf("%d ", a[i][j][k]);
            printf("\n");
        }
}