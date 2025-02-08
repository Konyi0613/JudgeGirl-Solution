#include <stdio.h>

#define ROW 3
#define COL 5

void multiplyMatrix(void **arrayA, void **arrayB, void **arrayC)
{
    int sz = 0;
    while (arrayA[sz] != NULL)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < ROW; j++)
            {
                for (int k = 0; k < COL; k++)
                {
                    int *a = (int *)arrayA[sz];
                    int *b = (int *)arrayB[sz];
                    int *c = (int *)arrayC[sz];
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        sz++;
    }
    return;
}