#include <stdio.h>
#include <stdint.h>
#include "blockmover.h"
#define down_check 0xFF00000000000000ULL
#define up_check 0x00000000000000FFULL
#define left_check 0x0101010101010101ULL
#define right_check 0x8080808080808080ULL
void printBlock(unsigned long long int *block)
{
    unsigned long long int mask = 1ULL;
    for (int i = 0; i < 64; i++)
    {
        printf("%llu", (*block >> i) & 1); // Extracts each bit for print without modifying `*block`
        if (i % 8 == 7)
            printf("\n"); // Print newline every 8 bits (for 8 rows)
    }
}

void initialize(unsigned long long int *block, int row, int column, int size)
{
    *block = 0;
    for (int i = 0; i < size; i++)
    {
        *block |= ((1ULL << size) - 1) << ((row + i) * 8 + column); // Set `size` bits directly in each row
    }
}

int moveLeft(unsigned long long int *block)
{
    if ((*block & left_check) != 0)
        return 0;
    *block = *block >> 1;
    return 1;
}

int moveRight(unsigned long long int *block)
{
    if ((*block & right_check) != 0)
        return 0;
    *block = *block << 1;
    return 1;
}

int moveUp(unsigned long long int *block)
{
    if ((*block & up_check) != 0)
        return 0;
    *block = *block >> 8;
    return 1;
}

int moveDown(unsigned long long int *block)
{
    if ((*block & down_check) != 0)
        return 0;
    *block = *block << 8;
    return 1;
}