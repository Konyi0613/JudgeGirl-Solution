#include <stdio.h>

int main()
{
    int a, b, c, d;
    int sum1, sum2, sum3, sum4;
    scanf("%d%d%d%d", &sum1, &sum2, &sum3, &sum4);
    for (a = sum1 - 3; a >= sum1 / 4; a--)
    {
        for (b = a - 1; b >= (sum1 - a) / 3; b--)
        {
            for (c = b - 1; c >= (sum1 - a - b) / 2; c--)
            {
                d = sum1 - a - b - c;
                if ((a + b + c + d == sum1) && (a * a + b * b + c * c + d * d == sum2) && (a * a * a + b * b * b + c * c * c + d * d * d == sum3) && (a * a * a * a + b * b * b * b + c * c * c * c + d * d * d * d == sum4))
                {
                    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
                    return 0;
                }
            }
        }
    }
    printf("-1");
}