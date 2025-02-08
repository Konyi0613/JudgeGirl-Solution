#include <stdio.h>
#include <stdbool.h>
bool fill_color(int N, int C, int P, int pair[P][2], int color[N], int index)
{
    if (index == N)
    {
        for (int i = 0; i < N; i++)
            printf("%d\n", color[i]);
        return true;
    }
    for (int i = 1; i <= C; i++)
    {
        bool used = false;
        for (int j = 0; j < P; j++)
            if ((pair[j][0] == index && color[pair[j][1]] == i) || (pair[j][1] == index && color[pair[j][0]] == i))
                used = true;
        if (!used)
        {
            color[index] = i;
            if (fill_color(N, C, P, pair, color, index + 1))
                return true;
            color[index] = 0;
        }
    }
    return false;
}

int main()
{
    int N, C, P;
    scanf("%d%d%d", &N, &C, &P);
    int pair[P][2];
    for (int i = 0; i < P; i++)
        scanf("%d%d", &pair[i][0], &pair[i][1]);
    int color[N];
    for (int i = 0; i < N; i++)
        color[i] = 0;
    if (!fill_color(N, C, P, pair, color, 0))
        printf("no solution.\n");
}