#include <stdio.h>
#include <stdint.h>

void minimum(int set_size, int subset_num, uint64_t subset_sum[subset_num], uint64_t set[set_size], int index, uint64_t *best, uint64_t now_sum)
{
    if (index == set_size)
    {
        if (now_sum < *best)
            *best = now_sum;
        return;
    }
    for (int i = 0; i < subset_num; i++)
    {
        uint64_t new_sum = now_sum - subset_sum[i] * subset_sum[i];
        subset_sum[i] += set[index];
        new_sum += subset_sum[i] * subset_sum[i];
        if (new_sum < *best)
            minimum(set_size, subset_num, subset_sum, set, index + 1, best, new_sum);
        subset_sum[i] -= set[index];
    }
    return;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    uint64_t set[n];
    for (int i = 0; i < n; i++)
        scanf("%lu", &set[i]);
    uint64_t best = INT64_MAX;
    uint64_t subset_sum[k];
    for (int i = 0; i < k; i++)
        subset_sum[i] = 0;
    minimum(n, k, subset_sum, set, 0, &best, 0);
    printf("%lu", best);
}