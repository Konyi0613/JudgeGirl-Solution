#include <stdio.h>
#include <stdint.h>

void find_min(int n, int k, int a[], int sum[], int *min, int id, int *max)
{
    if (id == n)
    {
        if (*max < *min)
            *min = *max;
        return;
    }
    if (*max >= *min)
        return;
    for (int i = 0; i < k; i++)
    {
        sum[i] += a[id];
        int original_max = *max;
        if (sum[i] > original_max)
            *max = sum[i];
        find_min(n, k, a, sum, min, id + 1, max);
        sum[i] -= a[id];
        *max = original_max;
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int sum[k];
    for (int i = 0; i < k; i++)
        sum[i] = 0;
    int min = INT32_MAX;
    int max = 0;
    find_min(n, k, a, sum, &(min), 0, &(max));
    printf("%d", min);
}