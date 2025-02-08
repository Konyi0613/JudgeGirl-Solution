#include <stdio.h>
#include "prepare_array.h"

void prepare_array(int buffer[], int *array[], int row, int column[])
{
    int exist = 0;
    for (int i = 0; i < row; i++)
    {
        array[i] = &(buffer[exist]);
        exist += column[i];
    }
}