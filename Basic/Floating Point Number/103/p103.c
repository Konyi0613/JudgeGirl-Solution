#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double a[n][n];
    double y[n];
    double x[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
    for (int i = n - 1; i >= 0; i--)
    {
        double tmp = y[i];
        for (int j = n - 1; j > i; j--)
            tmp -= a[i][j] * x[j];
        x[i] = tmp / a[i][i];
    }
    for (int i = 0; i < n; i++)
        printf("%f\n", x[i]);
}