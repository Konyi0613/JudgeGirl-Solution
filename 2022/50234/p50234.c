#include <stdio.h>
#include <assert.h>
#define MaxCube 100
#define MaxN 100001
#define MaxM 200002
#define MaxSize MaxN + MaxM
#define DEBUG 1

int GetLargest(int A[], int i, int size, int cube[])
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    if (left <= size && cube[A[left]] > cube[A[i]])
        largest = left;
    else
        largest = i;
    if (right <= size && cube[A[right]] > cube[A[largest]])
        largest = right;
    return largest;
}

void MaxHeapify(int A[], int i, int size, int cube[])
{
    int largest = GetLargest(A, i, size, cube);
    while (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        i = largest;
        largest = GetLargest(A, i, size, cube);
    }
}

void BuildMaxHeap(int A[], int size, int cube[])
{
    for (int i = MaxSize / 2; i >= 1; i--)
        MaxHeapify(A, i, size, cube);
}

int HeapExtractMax(int A[], int size, int cube[])
{
    assert(size >= 1);
    int max = A[1];
    A[1] = A[size];
    size -= 1;
    MaxHeapify(A, 1, size, cube);
    return max;
}

void MaxHeapInsert(int A[], int key, int size, int cube[])
{
    size++;
    int i = size;
    A[i] = key;
    while (i > 1 && cube[A[i / 2]] < cube[A[i]])
    {
        int temp = A[i];
        A[i] = A[i / 2];
        A[i / 2] = temp;
        i /= 2;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n * n + 1];
    int size = 0;
    int cube[n * n * n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                scanf("%d", &cube[i * n * n + j * n + k]);
                if (j == i || k == i)
                {
                    A[size + 1] = i * n * n + j * n + k;
                    size++;
                }
            }
        }
    }

    BuildMaxHeap(A, size, cube);

#if DEBUG == 0
    for (int i = 1; i <= n * n; i++)
        printf("%d ", cube[A[i]]);
    printf("\n");
#endif

    while (size > 0)
    {
        int maxloc = HeapExtractMax(A, size, cube);
        printf("%d ", cube[maxloc]);
        size -= 1;
        if (maxloc + n * n < n * n * n)
        {
            MaxHeapInsert(A, maxloc + n * n, size, cube);
            size++;
        }
    }
    return 0;
}