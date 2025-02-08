#include <stdio.h>

int main()
{
    long long n;
    while (scanf("%lld", &n) != EOF)
    {
        int bit = 0;
        int times = sizeof(long long) * 8;
        for (int i = 0; i < times; i++)
        {
            if ((n & 1) == 1)
                bit++;
            n >>= 1;
        }
        printf("%d\n", bit);
    }
}