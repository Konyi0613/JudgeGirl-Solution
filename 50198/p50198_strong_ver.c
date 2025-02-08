#include <stdio.h>
int num(int x)
{
    int a[10] = {0}, sum = 0;
    while (x != 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if (x % 10 == i)
            {
                a[i] = 1;
            }
        }
        x /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        sum += a[i];
    }
    return sum;
}
int main()
{
    int a, b, x;
    while (scanf("%d%d%d", &a, &b, &x) != EOF)
    {
        while (num(x) > 2)
        {
            x = (a * x) % b;
        }
        printf("%d\n", x);
    }
}