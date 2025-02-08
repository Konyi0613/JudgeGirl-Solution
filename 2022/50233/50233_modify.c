#include <stdio.h>
#include <assert.h>
#define MaxN 100001
#define MaxM 200002
#define MaxSize MaxN + MaxM

int GetLargest(int A[MaxSize], int i, int size)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    if (left <= size && A[left] > A[i])
        largest = left;
    else
        largest = i;
    if (right <= size && A[right] > A[largest])
        largest = right;
    return largest;
}

void MaxHeapify(int A[MaxSize], int i, int size)
{
    int largest = GetLargest(A, i, size);
    while (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        i = largest;
        largest = GetLargest(A, i, size);
    }
}

void BuildMaxHeap(int A[MaxSize], int n, int size)
{
    for (int i = MaxSize / 2; i >= 1; i--)
        MaxHeapify(A, i, size);
}

int HeapExtractMax(int A[MaxSize], int size)
{
    assert(size >= 1);
    int max = A[1];
    A[1] = A[size];
    size -= 1;
    MaxHeapify(A, 1, size);
    return max;
}

void MaxHeapInsert(int A[MaxSize], int key, int size)
{
    size++;
    int i = size;
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i])
    {
        int temp = A[i];
        A[i] = A[i / 2];
        A[i / 2] = temp;
        i /= 2;
    }
}

int main()
{
    int A[MaxSize];
    int n, m;
    scanf("%d", &n);
    int size = n;

    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    BuildMaxHeap(A, n, size);

    for (int i = 1; i <= n; i++)
        printf("%d ", A[i]);
    printf("\n");

    scanf("%d", &m);
    while (m--)
    {
        int input;
        scanf("%d", &input);
        if (input == -1)
        {
            printf("%d ", HeapExtractMax(A, size));
            size -= 1;
        }
        else
        {
            MaxHeapInsert(A, input, size);
            size++;
        }
    }
    printf("\n");
    return 0;
}