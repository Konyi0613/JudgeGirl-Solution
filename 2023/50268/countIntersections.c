#include <stdio.h>
#include "countIntersections.h"

#define MAX_ARR_SIZE 10000
//#define MAIN

int countIntersections(int **ptrArray)
{
    int len = 0;
    while (ptrArray[len] != NULL)
        len++;
    int intersection = 0;
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (ptrArray[j] - ptrArray[i] < 0)
                intersection++;
    return intersection;
}

#ifdef MAIN
int main(void) {
    int array[MAX_ARR_SIZE];
    int *ptrArray[MAX_PTR_ARR_SIZE];
    for (int i = 0; i < MAX_ARR_SIZE; i++) {
        array[i] = 0;
    }
    int n;
    scanf("%d", &n);
    int index[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &index[i]);
        ptrArray[i] = &array[index[i]];
    }
    ptrArray[n] = NULL;
    int numIntersections = countIntersections(ptrArray);
    printf("%d\n", numIntersections);
    return 0;
}
#endif