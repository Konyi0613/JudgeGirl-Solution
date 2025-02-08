#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    int poly1[n];
    for (int i = n - 1; i >= 0; i--)
        scanf("%d", &poly1[i]);
    scanf("%d", &m);
    int poly2[m];
    for (int i = m - 1; i >= 0; i--)
        scanf("%d", &poly2[i]);
    int degree_total = n - 1 + m - 1;
    int poly3[degree_total + 1];
    for (int i = 0; i < degree_total + 1; i++)
        poly3[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            poly3[i + j] += (poly1[i] * poly2[j]);
    for (int i = degree_total; i >= 1; i--)
        printf("%d ", poly3[i]);
    printf("%d", poly3[0]);
}