#include <stdio.h>
#include <stdint.h>
#include "numBitChanges.h"
int numBitChanges(GiantUnsignedInt *giantNum)
{
    int first;
    uint64_t cmp = 0x8000000000000000;
    int time = giantNum->n;
    first = ((giantNum->array[0] & cmp) >> 63);
    int now_bit = first;
    int change_time = 0;
    for (int i = 0; i < time; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            if ((giantNum->array[i] >> 63) != now_bit)
            {
                change_time++;
                now_bit = (1 - now_bit);
            }
            giantNum->array[i] <<= 1;
        }
    }
    change_time += (first != now_bit);
    return change_time;
}