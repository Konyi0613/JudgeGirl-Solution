#include <stdio.h>
#include <stdbool.h>
void fill_array(int *ptr[], int n)
{
    int index[n];
    bool used[n];
    for (int count = 0; count < n; count++)
    {
        index[count] = ptr[count] - ptr[0];
        used[count] = false;
    }
    int min = 0;
    used[0] = true;
    for (int i = 1; i < n; i++)
    {
        int second_min = n - 1;
        for (int j = 1; j < n - 1; j++)
        {
            if (index[j] < index[second_min] && used[j] == false)
                second_min = j;
        }
        used[second_min] = true;
        *ptr[min] = min;
        *ptr[second_min] = second_min;
        for (int j = index[min] + 1; j < index[second_min]; j++)
        {
            int *iptr = ptr[0];
            iptr += j;
            *iptr = min + second_min;
        }
        min = second_min;
    }
}