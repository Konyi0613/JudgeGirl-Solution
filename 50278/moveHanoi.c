#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#define MAXDISK 10
#define NUMROD 3
// #define DEBUG

void initialize(struct hanoi *hn, int n)
{
    hn->size = n;
    int *rod0 = (int *)malloc(sizeof(int) * n);
    int *rod1 = (int *)malloc(sizeof(int) * n);
    int *rod2 = (int *)malloc(sizeof(int) * n);
    hn->rod[0] = rod0;
    hn->rod[1] = rod1;
    hn->rod[2] = rod2;
    for (int i = 0; i < n; i++)
        hn->rod[0][i] = n - i - 1;
    hn->disk_num[0] = n;
    hn->disk_num[1] = 0;
    hn->disk_num[2] = 0;
}
void moveHanoi(struct hanoi *hn, int src, int dst)
{
    hn->rod[dst][hn->disk_num[dst]] = hn->rod[src][hn->disk_num[src] - 1];
    hn->disk_num[dst]++;
    hn->disk_num[src]--;
}
void printHanoi(struct hanoi *hn)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < hn->disk_num[i]; j++)
            printf(" %d", hn->rod[i][j]);
        printf("\n");
    }
    printf("\n");
}

#ifdef DEBUG
void hanoi(struct hanoi *hn, int n, int src, int dst, int buffer)
{
    if (n == 1)
    {
        moveHanoi(hn, src, dst);
        printHanoi(hn);
    }
    else
    {
        hanoi(hn, n - 1, src, buffer, dst);
        moveHanoi(hn, src, dst);
        printHanoi(hn);
        hanoi(hn, n - 1, buffer, dst, src);
    }
}
int main(void)
{
    int n;
    struct hanoi hn;

    scanf("%d", &n);

    initialize(&hn, n);
    printHanoi(&hn);
    hanoi(&hn, n, 0, 2, 1);

    return 0;
}
#endif