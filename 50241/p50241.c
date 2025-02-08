#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        uint64_t num;
        scanf("%lu", &num);
        int time = 64 / 5;
        for (int i = 0; i < time; i++)
        {
            int power = 1;
            int encode = 0;
            for (int j = 0; j < 5; j++)
            {
                int bit = (num & 1);
                num >>= 1;
                encode += power * bit;
                power *= 2;
            }
            // printf("%d ", encode);
            printf("%c", encode + 'a');
        }
    }
}