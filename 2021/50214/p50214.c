#include <stdio.h>

void print(int size, int a[size][size])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i][0]);
        for (int j = 1; j < size; j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }
}

int det(int size, int a[size][size], int original_size)
{
    print(size, a);
    if (size == 1)
        return a[0][0];
    int b[size - 1][size - 1];
    int determinant = 0;
    for (int col = 0; col < size; col++)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < col; j++)
                b[i - 1][j] = a[i][j];
            for (int j = col + 1; j < size; j++)
                b[i - 1][j - 1] = a[i][j];
        }
        int one;
        if (col % 2 == 0)
            one = 1;
        else
            one = -1;
        int new = one *a[0][col] * det(size - 1, b, original_size);
        determinant += new;
    }
    if (size != original_size)
        printf("determinant=%d\n", determinant);
    return determinant;
}

int main()
{
    int size;
    scanf("%d", &size);
    int a[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &a[i][j]);
    int determinant = det(size, a, size);
    printf("determinant=%d\n", determinant);
}