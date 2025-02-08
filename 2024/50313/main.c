#include <stdio.h>
#include <stdlib.h>
#include "split_cycle.h"

int main()
{
    int n, A, K;
    scanf("%d %d %d\n", &n, &A, &K);
    struct Node *a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &a[i]->val);
    }
    for (int i = 0; i < n; i++)
    {
        a[i]->nxt = a[(i + 1) % n];
    }
    int ans = split_cycle(a[0], A, K);  
    printf("%d\n", ans);
    return 0;
}
