#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int increase = e * f * g / (a * b);
    d = (d + increase > c) ? c : (d + increase);
    printf("%d", d);
}