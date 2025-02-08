#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "numZeroBits.h"
// #define MAIN

int numZeroBits(GiantUnsignedInt *giantNum)
{
    int max = 0;
    int now = 0;
    for (int i = giantNum->n - 1; i >= 0; i--)
        for (int j = 0; j < 64; j++)
        {
            uint64_t now_bit = giantNum->array[i] % 2;
            if (now_bit == 0)
                now++;
            else
            {
                if (now > max)
                    max = now;
                now = 0;
            }
            giantNum->array[i] >>= 1;
        }
    if (now > max)
        max = now;
    return max;
}
#ifdef MAIN
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        GiantUnsignedInt giantNum;
        for (int i = 0; i < n; i++)
            scanf("%llu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numZeroBits(&giantNum));
    }
    return 0;
}
#endif