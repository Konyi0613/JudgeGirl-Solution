#include <stdio.h>
#include <stdint.h>
#include "blockmover.h"

#define down_check 0xFF00000000000000ULL
#define up_check 0x00000000000000FFULL
#define left_check 0x0101010101010101ULL
#define right_check 0x8080808080808080ULL

void printBlock(const unsigned long long int *block)
{
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

inline int moveLeft(unsigned long long int *block)
{
    if ((*block & left_check) != 0)
        return 0;
    *block >>= 1;
    return 1;
}

inline int moveRight(unsigned long long int *block)
{
    if ((*block & right_check) != 0)
        return 0;
    *block <<= 1;
    return 1;
}

inline int moveUp(unsigned long long int *block)
{
    if ((*block & up_check) != 0)
        return 0;
    *block >>= 8;
    return 1;
}

inline int moveDown(unsigned long long int *block)
{
    if ((*block & down_check) != 0)
        return 0;
    *block <<= 8;
    return 1;
}
