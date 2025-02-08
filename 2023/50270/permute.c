#include <stdio.h>
#include <assert.h>
#include "permute.h"

// #define MAIN

void permute(int *ptrArray[MAX], int *ptrPerms[MAX])
{
    int size_perm = 0;
    while(ptrPerms[size_perm] != NULL)
        size_perm++;
    int size_arr = 0;
    while(ptrArray[size_arr] != NULL)
        size_arr++;
    for (int i = 0; i < size_perm; i++)
    {
        int *tmp[size_arr];
        for (int j = 0; j < size_arr; j++)
            tmp[j] = ptrArray[j];
        for (int j = 0; j < size_arr; j++)
            ptrArray[j] = tmp[ptrPerms[i][j]];
    }
}


#ifdef MAIN
int main() {
    int n, array[MAX], check[MAX];
    int *ptrArray[MAX];
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        ptrArray[i] = &array[i];
        scanf("%d", &array[i]);
        check[i] = array[i];
    }
    ptrArray[n] = NULL;
 
    int m, perms[MAX][MAX];
    int *ptrPerms[MAX];
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++)
            scanf("%d", &perms[i][j]);
        ptrPerms[i] = perms[i];
    }
    ptrPerms[m] = NULL; 
 
    permute(ptrArray, ptrPerms);
 
    for (int i = 0; i<n; i++) {
        assert(array[i] == check[i]);
        printf("%d ", *(ptrArray[i]));
    }
 
    return 0;
}
#endif