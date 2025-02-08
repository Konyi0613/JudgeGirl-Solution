#include <stdio.h>
#include <stdbool.h>
void count_collision(int *ptr[], int A[], int n, int a, int b, int c)
{
    bool used[c];
    for (int i = 0; i < c; i++)
    {
        A[i] = 0;
        used[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        int hash_value = (a * i + b) % c;
        ptr[i] = &(A[hash_value]);
        if (used[hash_value] == false)
            used[hash_value] = true;
        else
            A[hash_value]++;
    }
}