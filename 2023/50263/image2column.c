#include <stdio.h>
#include "image2column.h"

void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH])
{
    int row = 0, col = 0;
    for (int i = 0; i < (w - k + 1) * (h - k + 1); i++)
    {
        int step = 0;
        for (int row_count = row; row_count < row + k; row_count++)
        {
            for (int col_count = col; col_count < col + k; col_count++)
            {
                colMatrix[step][i] = imgMatrix[row_count][col_count];
                step++;
            }
        }
        if (col + k == w)
        {
            row++;
            col = 0;
        }
        else
        {
            col++;
        }
    }
}