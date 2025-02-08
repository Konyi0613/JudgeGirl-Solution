#include <stdio.h>
#include <math.h>

int main()
{
    long double a, b, c;
    while(scanf("%Lf%Lf%Lf", &a, &b, &c) != EOF)
    {
        long double D = sqrt(b * b - 4 * a * c);
        printf("%.20Lf %.20Lf\n", (-b - D)/(2*a), (-b + D)/(2*a));
    }

}