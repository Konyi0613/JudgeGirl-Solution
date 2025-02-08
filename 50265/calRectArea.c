#include <stdio.h>
#include <stdlib.h>
#include "calRectArea.h"
#define MAXM 200

int calRectArea(int N, int M, int *ptrMat, int *ptrLeft[], int *ptrRight[])
{
    int total_area = 0;
    int pos_right;
    int pos_left;
    int width;
    int height;
    for (int i = 0; i < M - 1; i++)
    {
        pos_right = (ptrRight[i] - ptrMat) % N;
        pos_left = (ptrLeft[i] - ptrMat) % N;
        width = pos_right - pos_left + 1;
        pos_right = (ptrRight[i] - ptrMat) / N;
        pos_left = (ptrLeft[i] - ptrMat) / N;
        height = pos_right - pos_left + 1;
        total_area += width * height;

        pos_right = (ptrRight[i] - ptrMat) % N;
        pos_left = (ptrLeft[i + 1] - ptrMat) % N;
        width = pos_right - pos_left + 1;
        pos_right = (ptrRight[i] - ptrMat) / N;
        pos_left = (ptrLeft[i + 1] - ptrMat) / N;
        height = pos_right - pos_left + 1;
        total_area -= width * height;
    }
    pos_right = (ptrRight[M - 1] - ptrMat) % N;
    pos_left = (ptrLeft[M - 1] - ptrMat) % N;
    width = pos_right - pos_left + 1;
    pos_right = (ptrRight[M - 1] - ptrMat) / N;
    pos_left = (ptrLeft[M - 1] - ptrMat) / N;
    height = pos_right - pos_left + 1;

    total_area += width * height;
    return total_area;
}
/*
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int *ptrMatrix;
    int matrix[N][N];
    int *ptrLeft[MAXM];
    int *ptrRight[MAXM];
    int x, y, w, h;

    ptrMatrix = &matrix[0][0];
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        ptrLeft[i] = &matrix[x][y];
        ptrRight[i] = &matrix[x + w - 1][y + h - 1];
    }
    int area = calRectArea(N, M, ptrMatrix, ptrLeft, ptrRight);
    printf("%d\n", area);
}*/