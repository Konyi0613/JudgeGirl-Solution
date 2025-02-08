#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void fill_array(int *ptr[], int n)
{
    for (int i = 0; ptr[0] + i != ptr[n - 1] + 1; i++)
    {
        *(ptr[0] + i) = 0;
    }

    for (int i = 0; i < n; i++)
    {
        *ptr[i] = i;
    }

    int last = 0;
    for (int i = 1; i < n; i++)
    {
        int count = 1;
        while (*(ptr[last] + count) == 0)
        {
            *(ptr[last] + count) += last;
            count++;
        }
        for (int j = 1; j < count; j++)
        {
            *(ptr[last] + j) += *(ptr[last] + count);
        }
        last = *(ptr[last] + count);
    }
    return;
}