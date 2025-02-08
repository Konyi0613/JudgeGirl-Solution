#include <stdio.h>
void matrix_multiplication(int N, int **ptrA, int M, int **ptrB, int S, int *result)
{
    int A[S][S], B[S][S];
    for (int i = 0; i < S; i++)
        for (int j = 0; j < S; j++)
        {
            A[i][j] = 0;
            B[i][j] = 0;
        }
    for (int i = 0; i < N; i++)
        A[ptrA[1][i]][ptrA[2][i]] = ptrA[0][i];
    for (int i = 0; i < M; i++)
        B[ptrB[1][i]][ptrB[2][i]] = ptrB[0][i];
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            int value = 0;
            for (int k = 0; k < S; k++)
                value += A[i][k] * B[k][j];
            result[i * S + j] = value;
        }
    }
}