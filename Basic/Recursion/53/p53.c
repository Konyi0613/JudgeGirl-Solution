#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void permutation(int num[], int n, int layer, int store[n], int used[n])
{
    if (layer >= n)
    {
        printf("%d", store[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", store[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        bool stop = false;
        for (int j = 0; j < layer; j++)
            if (used[j] == i)
                stop = true;
        if (stop)
            continue;
        store[layer] = num[i];
        used[layer] = i;
        permutation(num, n, layer + 1, store, used);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), cmp);
    int store[n];
    int used[n];
    permutation(num, n, 0, store, used);
}