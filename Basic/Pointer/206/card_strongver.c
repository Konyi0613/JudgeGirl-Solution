#include <stdio.h>

void shuffle(int *deck[])
{
    int size = 0;
    for (int i = 0; i < 10000; i++)
    {
        if (deck[i] == NULL)
            break;
        size++;
    }
    int size1 = (size + 1) / 2, size2 = size - size1;
    int *temp[size], ct1 = 0, ct2 = 0, index1 = 0, index2 = size1;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            temp[i] = deck[index1++];
        else
            temp[i] = deck[index2++];
    }
    for (int i = 0; i < size; i++)
        deck[i] = temp[i];
}

void print(int *deck[])
{
    int ct = 0;
    while (deck[ct] != NULL)
    {
        if (ct == 0)
            printf("%d", *deck[ct]);
        else
            printf(" %d", *deck[ct]);
        ct++;
    }
    if (ct != 0)
        printf("\n");
}