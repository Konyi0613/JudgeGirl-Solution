#include <stdio.h>
#include <stdbool.h>

int main()
{
    // search all vertices
    // record all length
    // find smallest
    int n;
    scanf("%d", &n);
    int v[n][n]; // v[start][end]
    bool used[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &v[i][j]);
    int shortest[n];
    for (int i = 0; i < n; i++)
    {
        for (int counter = 0; counter < n; counter++)
            used[counter] = false;
        int now_length = 0, head = i;
        for (int step = n; step > 0; step--)
        {
            int min_weight = -1, min_index = -1;
            if (step == 1)
            {
                now_length += v[head][i];
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (v[head][j] != 0 && used[j] == false && j != i)
                {
                    if (min_weight == -1 || v[head][j] <= min_weight)
                    {
                        min_weight = v[head][j];
                        min_index = j;
                    }
                }
            }
            now_length += min_weight;
            used[head] = true;
            head = min_index;
        }
        shortest[i] = now_length;
    }
    int min = shortest[0];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (shortest[i] <= min)
        {
            min = shortest[i];
            index = i;
        }
    }
    printf("%d %d\n", index + 1, min);
}