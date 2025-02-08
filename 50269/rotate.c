#include <stdio.h>
#include <assert.h>
#include "rotate.h"

// #define MAIN

void rotate(int *P[MAX][MAX], int n)
{
    int *tmp[n][n];
    for (int i = 0; i < n * n; i++)
        tmp[i / n][i % n] = P[i / n][i % n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            P[i][j] = tmp[n - 1 - j][i];
}

#ifdef MAIN
int main() {
    int array[MAX][MAX], check[MAX][MAX];
    int *P[MAX][MAX];
 
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            P[i][j] = &array[i][j];
            scanf("%d", &array[i][j]);
            check[i][j] = array[i][j];
        }
    }
 
    rotate(P, n);
 
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            assert(check[i][j] == array[i][j]);
            printf("%d ", *(P[i][j]));
        }
        printf("\n");
    }
 
    return 0;
}
#endif