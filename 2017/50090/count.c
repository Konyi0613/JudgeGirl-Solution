#include <stdio.h>

void count(int **p[])
{
    int type_time[512] = {0};
    int n = 0;
    int ptr_type = 0;
    int *type[512];
    while (p[n] != NULL)
    {
        int index = -1;
        for (int i = 0; i < ptr_type; i++)
        {
            if (*p[n] == type[i])
                index = i;
        }
        if (index == -1)
        {
            type[ptr_type] = *p[n];
            type_time[ptr_type] = 1;
            ptr_type++;
        }
        else
            type_time[index]++;
        n++;
    }
    for (int i = 0; i < ptr_type; i++)
    {
        for (int j = 0; j < ptr_type - 1 - i; j++)
        {
            if (type_time[j] > type_time[j + 1] || (type_time[j] == type_time[j + 1] && *type[j] > *type[j + 1]))
            {
                int tmp = type_time[j];
                type_time[j] = type_time[j + 1];
                type_time[j + 1] = tmp;
                tmp = *type[j];
                *type[j] = *type[j + 1];
                *type[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < ptr_type; i++)
        printf("%d %d\n", *type[i], type_time[i]);
}