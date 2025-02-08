#include <stdio.h>
#include <stdbool.h>

int main()
{
    int m, C;
    scanf("%d%d", &m, &C);
    int s[m], remain[m];
    for (int i = 0; i < m; i++)
    {
        remain[i] = C;
        scanf("%d", &s[i]);
    }
    int best_fit = 0;
    for (int i = 0; i < m; i++)
    {
        int min = C, min_index = 0;
        for (int j = 0; j < m; j++)
        {
            if (remain[j] < min && remain[j] >= s[i])
            {
                min = remain[j];
                min_index = j;
            }
        }
        if (min == C)
        {
            remain[best_fit] -= s[i];
            best_fit++;
        }
        else
        {
            remain[min_index] -= s[i];
        }
    }
    printf("%d ", best_fit);
    int first_fit = 0;
    for (int i = 0; i < m; i++)
        remain[i] = C;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (remain[j] >= s[i])
            {
                if (remain[j] == C)
                    first_fit++;
                remain[j] -= s[i];
                break;
            }
        }
    }
    printf("%d ", first_fit);
    int worst_fit = 0;
    for (int i = 0; i < m; i++)
        remain[i] = C;
    for (int i = 0; i < m; i++)
    {
        int max = 0, max_index = 0;
        for (int j = 0; j < m; j++)
        {
            if (remain[j] >= s[i] && remain[j] > max && remain[j] != C)
            {
                max = remain[j];
                max_index = j;
            }
        }
        if (max == 0)
        {
            remain[worst_fit] -= s[i];
            worst_fit++;
        }
        else
        {
            remain[max_index] -= s[i];
        }
    }
    printf("%d\n", worst_fit);
}