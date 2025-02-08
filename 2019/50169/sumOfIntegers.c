#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks)
{
    int start = 0, end = 0, block_count = 0;
    bool end_loop = false;
    while (!end_loop)
    {
        while (ptrArray[end] != NULL)
            end++;
        if (ptrArray[end + 1] == NULL)
            end_loop = true;
        int sum = 0;
        for (int i = start; i < end; i++)
        {
            bool used = false;
            for (int j = start; j < i; j++)
                if (ptrArray[i] == ptrArray[j])
                {
                    used = true;
                    break;
                }
            if (!used)
                sum += *ptrArray[i];
        }
        answer[block_count] = sum;
        start = end + 1;
        end++;
        block_count++;
    }
    *numberOfBlocks = block_count;
    return;
}