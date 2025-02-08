#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxN 100001
#define MaxM 200002
#define MaxSize MaxN + MaxM
int get_largest(int num[], int n, int i)
{
    int largest;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= n && num[l] > num[i])
        largest = l;
    else
        largest = i;
    if (r <= n && num[r] > num[largest])
        largest = r;
    return largest;
}
void max_heapify(int num[], int n, int i)
{
    int largest = get_largest(num, n, i);
    while (largest != i)
    {
        int temp = num[i];
        num[i] = num[largest];
        num[largest] = temp;
        i = largest;
        largest = get_largest(num, n, i);
    }
}
void build_max_heap(int num[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        max_heapify(num, n, i);
    }
}
int heap_extract_max(int num[], int n)
{
    int max = num[1];
    num[1] = num[n];
    n -= 1;
    max_heapify(num, n, 1);
    return max;
}
void max_heap_insert(int num[], int n, int operator)
{
    n++;
    int i = n;
    num[i] = operator;
    while (i > 1 && num[i / 2] < num[i])
    {
        int temp = num[i];
        num[i] = num[i / 2];
        num[i / 2] = temp;
        i /= 2;
    }
}
int main()
{
    int n, m;
    int num[MaxSize];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
    }
    int size = n;
    build_max_heap(num, size);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int operator;
        scanf("%d", &operator);
        if (operator== - 1)
        {
            printf("%d ", heap_extract_max(num, size));
            size -= 1;
        }
        else
        {
            max_heap_insert(num, size, operator);
            size++;
        }
    }
    printf("\n");
}