#include <stdio.h>

int main()
{
    double a, b, c, pi = 3.1415926;
    scanf("%lf%lf%lf", &a, &b, &c);
    double area = 0;
    area += c * c * pi / 4;
    double d = c;
    d -= b;
    if (d > 0)
        area += d * d * pi / 4;
    d = c;
    area += d * d * pi / 2;
    d -= a;
    if (d > 0)
        area += d * d * pi / 4;
    printf("%f", area);
}