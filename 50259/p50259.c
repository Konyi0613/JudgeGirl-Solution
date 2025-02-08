#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double data[n];
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &data[i]);
        sum += data[i];
    }
    double avg = sum / n;
    printf("%f\n", avg);
    sum = 0;
    for (int i = 0; i < n; i++)
        sum += (data[i] - avg) * (data[i] - avg);
    printf("%f", sum / n);
}