#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int r[n], c[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d", &r[i], &c[i]);
    int ry, cy;
    scanf("%d%d", &ry, &cy);
    int min_value = (r[0] - ry) * (r[0] - ry) + (c[0] - cy) * (c[0] - cy);
    for (int i = 1; i < n; i++)
    {
        if ((r[i] - ry) * (r[i] - ry) + (c[i] - cy) * (c[i] - cy) < min_value)
            min_value = (r[i] - ry) * (r[i] - ry) + (c[i] - cy) * (c[i] - cy);
    }
    for (int i = 0; i < n; i++)
    {
        if ((r[i] - ry) * (r[i] - ry) + (c[i] - cy) * (c[i] - cy) == min_value)
            printf("%d\n", i);
    }
}