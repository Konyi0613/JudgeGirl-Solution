#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 5
#define MAX 10
typedef int A[ROW][COL];
typedef int B[COL][ROW];
typedef int C[ROW][ROW];

void multiplyMatrix(void **arrayA, void **arrayB, void **arrayC)
{
    int n = 0;
    while (arrayA[n] != NULL)
    {
        int(*A)[COL] = (int(*)[COL])arrayA[n]; // Cast to correct type
        int(*B)[ROW] = (int(*)[ROW])arrayB[n]; // Cast to correct type
        int(*C)[ROW] = (int(*)[ROW])arrayC[n]; // Cast to correct type

        // Perform matrix multiplication A * B = C
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < ROW; j++)
            {
                C[i][j] = 0; // Initialize C[i][j] to 0
                for (int k = 0; k < COL; k++)
                {
                    C[i][j] += A[i][k] * B[k][j]; // Matrix multiplication logic
                }
            }
        }
        n++;
    }
}