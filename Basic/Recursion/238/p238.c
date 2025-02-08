#include <stdio.h>

int subset(int set[], int n, int target, int index)
{
    if (index >= n)
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }

    if (set[index] > target)
        return subset(set, n, target, index + 1);
    return (subset(set, n, target, index + 1) + subset(set, n, target - set[index], index + 1));
}

int main()
{
    int n;
    scanf("%d", &n);
    int set[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    int target;
    while (scanf("%d", &target) != EOF)
        printf("%d\n", subset(set, n, target, 0));
}