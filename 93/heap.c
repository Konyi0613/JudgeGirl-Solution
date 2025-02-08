#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

void initialize(struct Heap *heap)
{
    heap->num = 0;
    return;
}
int removeMin(struct Heap *heap)
{
    (heap->num)--;
    return heap->ary[heap->num];
}
void add(struct Heap *heap, int i)
{
    int id = -1;
    for (int j = (heap->num) - 1; j >= 0; j--)
        if (heap->ary[j] < i)
            heap->ary[j + 1] = heap->ary[j];
        else
        {
            id = j;
            break;
        }
    heap->ary[id + 1] = i;
    (heap->num)++;
    return;
}
int isFull(struct Heap *heap)
{
    if (heap->num == MAXHEAP)
        return 1;
    else
        return 0;
}
int isEmpty(struct Heap *heap)
{
    if (heap->num == 0)
        return 1;
    else
        return 0;
}
/*
int main(){
    struct Heap myHeap;
    int n;
    scanf("%d", &n);
    initialize(&(myHeap));
    for (int i = 0; i < n; i++)
    {
        int j;
        scanf("%d", &j);
        add(&(myHeap), j);
        for (int x = 0; x < myHeap.num; x++)
            printf("%d ", myHeap.ary[x]);
        printf("\n");
    }
}
*/