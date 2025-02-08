#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int bit = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n & 1) == 1)
                bit++;
            n >>= 1;
        }
        printf("%d\n", bit);
    }
}