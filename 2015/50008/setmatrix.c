#include <stdio.h>
#include "setmatrix.h"

void processSetMatrix(int ***ptr)
{
    int matrix_sz = 0;
    while (ptr[matrix_sz] != NULL)
        matrix_sz++;
    for (int i = 0; i < matrix_sz; i++)
    {
        int array_sz = 0;
        while (ptr[i][array_sz] != NULL)
            array_sz++;
        for (int j = 0; j < array_sz; j++)
        {
            int set_size = 0;
            // int *set_ptr = &(ptr[i][j][set_size]);
            while (ptr[i][j][set_size] != 0)
            {
                // set_ptr++;
                set_size++;
            }
            for (int k = 0; k < set_size; k++)
            {
                if (i == matrix_sz - 1 && j == array_sz - 1 && k == set_size - 1)
                    printf("%d", ptr[i][j][k]);
                else
                    printf("%d ", ptr[i][j][k]);
            }
        }
    }
}