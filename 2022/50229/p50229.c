#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    int capacity[k];
    int volume[k];
    for (int i = 0; i < k; i++)
        scanf("%d", &capacity[i]);
    for (int i = 0; i < k; i++)
        scanf("%d", &volume[i]);
    int i, j;
    while (scanf("%d%d", &i, &j) != EOF)
    {
        if (i == k)
        {
            volume[j] = capacity[j];
        }
        else if (j == k)
        {
            volume[i] = 0;
        }
        else
        {
            if (capacity[j] - volume[j] >= volume[i])
            {
                volume[j] += volume[i];
                volume[i] = 0;
            }
            else
            {
                int tmp = capacity[j] - volume[j];
                volume[j] = capacity[j];
                volume[i] -= tmp;
            }
        }
    }
    printf("%d", volume[0]);
    for (int counter = 1; counter < k; counter++)
        printf(" %d", volume[counter]);
}