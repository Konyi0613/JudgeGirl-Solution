#include <stdio.h>
int gcd(int x, int y)
{
    if (x % y == 0 || y % x == 0)
    {
        return ((x >= y) ? y : x);
    }
    if (x > y)
    {
        return gcd(x % y, y);
    }
    else
    {
        return gcd(y % x, x);
    }
}
int main()
{
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int denominator1, numerator1, denominator2, numerator2;
    if (b == 0)
    {
        denominator1 = 1;
        numerator1 = a;
    }
    else
    {
        denominator1 = c;
        if (a > 0)
        {
            numerator1 = c * a + b;
        }
        else
        {
            numerator1 = c * a - b;
        }
    }

    // printf("nume1: %d denom1: %d \n", numerator1, denominator1);
    if (f == 0)
    {
        denominator2 = 1;
        numerator2 = e;
    }
    else
    {
        denominator2 = g;
        if (e > 0)
        {
            numerator2 = g * e + f;
        }
        else
        {
            numerator2 = g * e - f;
        }
    }

    // printf("nume2: %d denom2: %d \n", numerator2, denominator2);
    int denominator3, numerator3;
    switch (d)
    {
    case 0:
        denominator3 = denominator1 * denominator2;
        numerator3 = numerator1 * denominator2 + numerator2 * denominator1;
        break;
    case 1:
        denominator3 = denominator1 * denominator2;
        numerator3 = numerator1 * denominator2 - numerator2 * denominator1;
        break;
    case 2:
        denominator3 = denominator1 * denominator2;
        numerator3 = numerator1 * numerator2;
        break;
    case 3:
        // a/b / c/d = a/b * d/c = ad/bc
        denominator3 = denominator1 * numerator2;
        numerator3 = denominator2 * numerator1;
        if (denominator3 < 0)
        {
            numerator3 *= (-1);
            denominator3 *= (-1);
        }
        break;
    default:
        printf("wtf");
        break;
    }
    // printf("%d %d", numerator3, denominator3);

    // printf("nume3: %d denom3: %d\n", numerator3, denominator3);
    int h, i, j;
    if (numerator3 > 0)
    {
        // printf("gcd= %d\n", gcd(numerator3, denominator3));
        int temp_nume3 = numerator3;
        temp_nume3 /= gcd(numerator3, denominator3);
        denominator3 /= gcd(numerator3, denominator3);
        h = temp_nume3 / denominator3;
        if (temp_nume3 % denominator3 == 0)
        {
            i = 0;
            j = 1;
        }
        else
        {
            i = temp_nume3 % denominator3;
            j = denominator3;
        }
    }
    else
    {
        numerator3 *= (-1);
        // printf("gcd= %d\n", gcd(numerator3, denominator3));
        int temp_nume3 = numerator3;
        temp_nume3 /= gcd(numerator3, denominator3);
        denominator3 /= gcd(numerator3, denominator3);
        // printf("%d, %d \n", temp_nume3, denominator3);
        h = temp_nume3 / denominator3 * (-1);
        if (temp_nume3 % denominator3 == 0)
        {
            i = 0;
            j = 1;
        }
        else
        {
            i = temp_nume3 % denominator3;
            j = denominator3;
        }
    }
    printf("%d\n%d\n%d\n", h, i, j);
}