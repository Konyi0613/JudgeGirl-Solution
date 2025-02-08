#include <stdio.h>
#include "evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index)
{
    int *iptr0 = iptr[0];
    int x = *iptr[0];
    *iptr0++;
    int y = *iptr0;
    int value, max = 4 * x - 6 * y, max_index = 0;
    for (int i = 1; i < n; i++)
    {
        x = *iptr[i];
        iptr0 = iptr[i];
        *iptr0++;
        y = *iptr0;
        value = 4 * x - 6 * y;
        if (value > max)
        {
            max = value;
            max_index = i;
        }
    }
    *index = max_index;
    return max;
}