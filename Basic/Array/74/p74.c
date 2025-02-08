#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int m;
    scanf("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int j = a[i] % m;
        b[j]++;
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", b[i]);
}