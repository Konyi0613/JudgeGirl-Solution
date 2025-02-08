#include <stdio.h>

int main()
{
    int t1, t2;
    scanf("%d", &t1);
    int min = 86400;
    while (scanf("%d", &t2) != EOF)
    {
        int s1 = (t1 / 10000) * 3600 + ((t1 / 100) % 100) * 60 + t1 % 100;
        int s2 = (t2 / 10000) * 3600 + ((t2 / 100) % 100) * 60 + t2 % 100;
        int d = s1 - s2;
        if (d < 0)
            d = -d;
        if (d < min)
            min = d;
        t1 = t2;
    }
    printf("%d", min);
}