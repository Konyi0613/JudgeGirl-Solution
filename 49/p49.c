#include <stdio.h>
#include <stdbool.h>
int main()
{
    int N, m;
    scanf("%d%d", &N, &m);
    int sum[m];
    int max[m];
    int min[m];
    bool found[m];
    for (int i = 0; i < m; i++)
    {
        sum[i] = 0;
        max[i] = 0;
        min[i] = 0;
        found[i] = false;
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        int remainder = num % m;
        sum[remainder] += num;
        if (num >= max[remainder])
            max[remainder] = num;
        if (found[remainder] == false || num <= min[remainder])
        {
            min[remainder] = num;
            found[remainder] = true;
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d %d %d\n", sum[i], max[i], min[i]);
}