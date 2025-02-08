#include <stdio.h>
int C(int n, int k)
{
    if (k == 0)
        return 1;
    int c = 1;
    for (int i = n - k + 1; i <= n; i++)
        c *= i;
    for (int i = 1; i <= k; i++)
        c /= i;
    return c;
}
int main()
{
    int F = 0;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= k; i++)
        F += C(n, i);
    printf("%d", F);
}