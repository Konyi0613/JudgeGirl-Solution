#include <stdio.h>
#include "max.h"

int max(int *iptr[], int n)
{
    int max = *iptr[0];
    int counter = 1;
    while (counter < n)
    {
        if (*iptr[counter] > max)
            max = *iptr[counter];
        counter++;
    }
    return max;
}