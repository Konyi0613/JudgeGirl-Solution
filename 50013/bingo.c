#include <stdio.h>
#include <stdint.h>

int bingo(const unsigned long long int *board, int *rowColumn)
{
    uint64_t row_type = (255ULL << 56), col_type = 1ULL, dg1 = 1ULL, dg2 = (1ULL << 7);
    for (int i = 0; i < 7; i++)
    {
        col_type = (col_type << 8) + 1ULL;
        dg1 = (dg1 << 9) + 1ULL;
        dg2 = (dg2 << 7) + (1ULL << 7);
    }
    col_type = (col_type << 7);
    //row
    for (int i = 0; i < 8; i++)
        if ((*board & (row_type >> (i * 8))) == (row_type >> (i * 8)))
        {
            *rowColumn = i;
            return 1;
        }
    //col
    for (int i = 0; i < 8; i++)
        if ((*board & (col_type >> i)) == (col_type >> i))
        {
            *rowColumn = i;
            return 2;
        }
    //dg1
    if ((*board & dg1) == dg1)
    {
        *rowColumn = 0;
        return 3;
    }
    //dg2
    if ((*board & dg2) == dg2)
    {
        *rowColumn = 1;
        return 3;
    }
    return 0;
}