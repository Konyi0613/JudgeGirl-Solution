#include <stdio.h>

int main()
{
    int a0 = 0, a1 = 0, a2 = 0;
    int *a[3];
    a[0] = &a0;
    a[1] = &a1;
    a[2] = &a2;
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; i++)
    {
        int res = num[i] % 3;
        (*a[res])++;
    }
    printf("%d %d %d", *a[0], *a[1], *a[2]);
}